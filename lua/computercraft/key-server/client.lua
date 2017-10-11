local modemSide = "top" -- Wireless/Wired modem
local serverID = 1 -- Key Server ID

os.pullEvent = os.pullEventRaw

term.clear()
term.setCursorPos(1,1)

rednet.open(modemSide)
rednet.send(serverID, "getPass")

print("Waiting for key server...")

id, msg, dist = rednet.receive()

rednet.send(serverID, "response")
rednet.close()

term.clear()
term.setCursorPos(1,1)

print("-- olbOS --")
print("Password: ")

term.setCursorPos(11,2)

input = read("*")

if input == msg then
  term.clear()
  term.setCursorPos(1,1)
  print("Welcome!")
  
else

  term.clear()
  term.setCursorPos(1,1)
  print("Denied")
  sleep(3)
  os.reboot()
  
end
