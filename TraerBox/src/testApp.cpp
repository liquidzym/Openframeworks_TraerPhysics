#include "testApp.h"

float width;
float height;

ofLight light;

//--------------------------------------------------------------
void testApp::setup(){

	width = ofGetWidth();
	height = ofGetHeight();

	xRotation = 0;
	yRotation = 0;

	bounceDamp = 0.5;
	repulsionStrength = 5;
	repulsionMinimum = 5;

	gravityMagnitude = 1;

	physics = new ParticleSystem( gravityMagnitude, 0.01 );
	eulerInter = new ModifiedEulerIntegrator(physics);
	physics->setIntegrator( eulerInter );		// Equal to P5 : physics.setIntegrator( ParticleSystem.MODIFIED_EULER );

	for ( int i = 0; i < NUM_LITTLEBOX; i++ )
	{
		Particle* p = physics->makeParticle(1, 
			ofRandom( -0.45*LITTLEBOX_SIZE, 0.45*LITTLEBOX_SIZE ), 
			ofRandom( -0.45*LITTLEBOX_SIZE, 0.45*LITTLEBOX_SIZE ), 
			ofRandom( -0.45*LITTLEBOX_SIZE, 0.45*LITTLEBOX_SIZE ) );

		// link all particle
		for ( int j = 0; j < i; j++ )
		{
			Particle* q = physics->getParticle(j);
			physics->makeAttraction( p, q, -repulsionMinimum, repulsionMinimum );
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){

	setRotation( -0.02*(mouseY - ofGetHeight()/2), 0.02*(mouseX - ofGetWidth()/2) );

	physics->tick();

	bounce();
}

//--------------------------------------------------------------
void testApp::draw(){

	//ofEnableLighting();
	light.enable();
	glEnable(GL_DEPTH_TEST);

	ofPushMatrix();
	ofTranslate( width/2, height/2 );
	ofRotateX( xRotation );
	ofRotateY( yRotation );

	for ( int i = 0; i < physics->numberOfParticles(); i++ )
	{
		ofPushMatrix();

		Particle* p = physics->getParticle(i);
		ofTranslate( p->mPos );

		ofBox( LITTLEBOX_SIZE );

		ofPopMatrix();
	}

	ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}