#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	width = ofGetWidth();
	height = ofGetHeight();

	physics	= new ParticleSystem( 1, 0.05 );

	p = physics->makeParticle( 1.0, width*.5, height*.5, 0);

	anchor = physics->makeParticle( 1.0, width*.5, height*.5, 0);
	anchor->setFixed(true);

	s = physics->makeSpring( p, anchor, 0.5, 0.1, 75 );

}

//--------------------------------------------------------------
void testApp::update(){
	physics->tick();
}

//--------------------------------------------------------------
void testApp::draw(){

	ofLine( p->mPos, anchor->mPos );
	ofCircle( anchor->mPos, 5 );
	ofCircle( p->mPos, 20 );

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
	p->mPos.set(x, y, 0);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	p->setFixed(true);
	p->mPos.set(x, y, 0);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	p->setFixed(false);		// p5 : makeFree()
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