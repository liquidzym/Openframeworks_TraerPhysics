#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	width = ofGetWidth();
	height = ofGetHeight();

	physics = new ParticleSystem(0, 0.1);
	initialize();

}

//--------------------------------------------------------------
void testApp::update(){
	physics->tick();

	if ( physics->numberOfParticles() > 1 )
		updateCentroid();
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix();

	ofTranslate( width*0.5, height*0.5);
	ofScale(scale, scale, scale);

	ofTranslate( -centroidX, -centroidY );

	// draw network
	for ( int i = 0; i < physics->numberOfParticles(); ++i )
	{
		Particle* v = physics->getParticle(i);
		ofCircle( v->mPos, NODE_SIZE);
	}

	//glBegin(GL_LINES);
	for ( int i = 0; i < physics->numberOfSprings(); ++i )
	{
		Spring* e = physics->getSpring(i);
		Particle* a = e->getOneEnd();
		Particle* b = e->getTheOtherEnd();
		ofLine( a->mPos, b->mPos );
	}
	//glEnd();

	ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if ( key == 'c' ) initialize();
	if ( key == ' ' ) addNode();
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
	addNode();
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