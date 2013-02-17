#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	physics = new ParticleSystem(0, 0.1);

	m = physics->makeParticle();
	m->setFixed(true);

	for ( int i = 0; i < 1000; i++ )
	{
		Particle* p = physics->makeParticle( 1.0, ofRandomWidth(), ofRandomHeight(), 0);
		physics->makeAttraction( m, p, 5000, 50);

		others.push_back(p);
	}

}

//--------------------------------------------------------------
void testApp::update(){
	physics->tick();
}

//--------------------------------------------------------------
void testApp::draw(){

	ofNoFill();
	for ( int i = 0; i < others.size(); i++ )
	{
		ofCircle( others[i]->mPos, 10 );	// img replace
	}

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
	m->mPos.set(x, y, 0);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	m->mPos.set(x, y, 0);
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