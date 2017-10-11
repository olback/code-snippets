local modemSide = "top" -- Wireless/Wired modem
local password = "kek" -- Make it secure! This will be hashed and moved to a sperate file in the future.

os.pullEvent = os.pullEventRaw

term.clear()
term.setCursorPos(1,1)
print("-- olbOS Server v1.0 --")
print("Server ID: ", os.getComputerID())
rednet.open(modemSide)

while true do
  id, msg, dist = rednet.receive()
  
  if msg == "getPass" then
    rednet.send(id, password)
    print("Sent to #", id)
  end
  
  if msg == "response" then
    print("Delivered to #", id)
  end
  
end
