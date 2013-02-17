#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


	physics = new ParticleSystem();

	mpart = physics->makeParticle();
	mpart->setFixed(true);			// Equal P5 particle.makeFixed();

	mb = physics->makeParticle( 1.0, ofRandomWidth(), ofRandomHeight(), 0 );
	mc = physics->makeParticle( 1.0, ofRandomWidth(), ofRandomHeight(), 0 );

	physics->makeAttraction( mpart, mb, 10000, 20);
	physics->makeAttraction( mpart, mc, 10000, 20);
	physics->makeAttraction( mb,    mc, -10000, 5);

}

//--------------------------------------------------------------
void testApp::update(){
	float t = ofGetLastFrameTime();

	handleBoundaryCollisions(mb);
	handleBoundaryCollisions(mc);

	physics->tick(t*10);
}

//--------------------------------------------------------------
void testApp::draw(){

	ofNoFill();
	ofCircle( mpart->mPos, 20);

	ofFill();
	ofCircle( mb->mPos, 20);
	ofCircle( mc->mPos, 20);

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
	mpart->mPos.set(x, y, 0);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	mpart->mPos.set(x, y, 0);
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