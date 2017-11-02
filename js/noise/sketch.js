const w = window.innerWidth; // Canvas width.
const h = window.innerHeight; // Canvas height.

const inc = 0.0015; // xoff incroment.
let xoff = 0;
let y;

function setup() {
  createCanvas(w, h);
  drawCurve();
  fill(255);
  noStroke();
  textSize(18);
  textAlign(CENTER);
  text('Press the mouse to generate a new curve!', w / 2, 22);
}

function mousePressed() {
  drawCurve();
}

function drawCurve() {
  background(51); // Background grayscale 51.
  noFill(); // No fill.
  strokeWeight(3); // Stroke weight 3.
  stroke(80); // Stroke color. The color of the curve.

  beginShape();

  for (let i = 0; i < windowWidth; i++) {
    n = noise(xoff);
    y = map(n, 0, 1, 100, windowHeight - 100);
    vertex(i, y);
    xoff += inc;
  }

  endShape();
}