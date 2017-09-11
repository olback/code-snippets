// Hide div with id #open-console when dev console is opend
var devC = new Image();
Object.defineProperty(devC, 'id', {
  get: function () {
    devConsole.hidden = true;
  }
});
console.log('%cHello', devC);
