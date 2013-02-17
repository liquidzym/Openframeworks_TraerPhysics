import traer.physics.*;


int SQUARE = 1;
int CIRCLE = 2;

int TOTAL_PARTICLES = 400;
int USE_PARTICLES = 400;

/* The shape used to represent the particles */
int shape = 1;

/* The  Particle System */
ParticleSystem mundo;

/* The particles connected to the mouse */
Particle p[];

/* The particle that follows the mouse  */
Particle rato;

/* The springs between the mouse and the other particles */
Spring []spring;


void setup() {
  size(800,600, P3D);

  // gravidade 0.1 e atrito 0.1
  mundo = new ParticleSystem(0, 5.5);

  rato = mundo.makeParticle(1, 0, 0, 0);
  rato.makeFixed();

  p = new Particle[TOTAL_PARTICLES];
  spring = new Spring[TOTAL_PARTICLES];

  for (int i = 0; i < TOTAL_PARTICLES; i++) {

    p[i] = mundo.makeParticle(5+i, 0, 0, 0);
    spring[i] = mundo.makeSpring(rato, p[i], 2.0, 0.051, random(10,100));
  }


}

void draw() {

  if (frameCount % 10 == 0){
    fill(0, 0.01);

    noStroke();
    rect(0, 0, width, height);
  }
  fill(255);
  stroke(255);

  rato.position().set(mouseX, mouseY, 0);


  for (int i = 0; i < USE_PARTICLES; i++) {

    fill(sin(frameCount*0.01)*127+127, sin(frameCount*0.02)*127+127, cos(frameCount*0.01)*127+127, 255-p[i].mass()/400.0*255);

    noStroke();

    pushMatrix();
    translate(p[i].position().x()+10, p[i].position().y()+10, 0);
    rotateZ(frameCount*0.05);
    translate(-p[i].position().x()-10, -p[i].position().y()-10, 0);

    if (shape == SQUARE) {
      rect(p[i].position().x(), p[i].position().y(), 20, 20);
    } 
    else if (shape == CIRCLE) {
      ellipse(p[i].position().x(), p[i].position().y(), 20, 20);
    }

    popMatrix();
    stroke(100);    
  }

  mundo.tick();
}

void keyPressed() {
  
  /* all the particles are at the same distance from the mouse */
  if (key == 'c') {
    float l = random (10, 100);
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
      spring[i].setRestLength(l);
    }
  } 
  /* the distance between the particle and the mouse increases */
  else if (key == 'e') {
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
      spring[i].setRestLength(i/(TOTAL_PARTICLES*1.0)*100);
    }
  } 
  /* random distances */
  else if (key == 'r') {
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
      spring[i].setRestLength(random(10, 100));
    }
  } 
  else if( key == '1') {
    shape = SQUARE;
  } 
  else if (key == '2') {
    shape = CIRCLE;
  }
  else if (key == ' ' ) {
    saveFrame("dynbrush####.png");
    }


}
