// Hide div with id #open-console when dev console is opend
const message = document.getElementById("message");
var devC = new Image();
Object.defineProperty(devC, 'id', {
  get: function () {
    message.innerHTML = "Developer console opend!";
  }
});
console.log('%cHello', devC);
