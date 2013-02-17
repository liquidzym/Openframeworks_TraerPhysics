#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	physics = new ParticleSystem(0.0, 0.05);

	m = physics->makeParticle();
	m->setFixed(true);

	drawing = false;
	greyer = 255;

	tendrils.clear();

	ofEnableSmoothing();
}

//--------------------------------------------------------------
void testApp::update(){
	

	if ( !drawing )
	{
		physics->tick();
		if ( greyer < 255 ) 
			greyer *= 1.11111;		// thrive?
		if ( greyer > 255 ) 
			greyer = 255;
	}
	else
	{
		if ( greyer >= 64 )
			greyer *= 0.9;			// decay?
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(255);

	ofSetColor(255-greyer);
	for ( int i = 0; i < ((int)tendrils.size() - 1); i++ )
	{
		T3ndril* t = &tendrils.at(i);
		drawElastic(t);
	}

	if ( (int)tendrils.size() > 0 )
	{
		T3ndril* t = &tendrils.back();
		drawElastic( t );
	}
		
}

void testApp::drawElastic( T3ndril* t)
{
	float lastStretch = 1;
	for ( int i = 0; i < (int)t->particles.size()-1; ++i )
	{
		ofVec3f firstPoint = ((Particle*)t->particles.at( i ))->mPos;
		ofVec3f firstAnchor =  i < 1 ? firstPoint : ((Particle*)t->particles.at( i-1 ))->mPos;
		ofVec3f secondPoint = i+1 < t->particles.size() ? ((Particle*)t->particles.at( i+1 ))->mPos : firstPoint;
		ofVec3f secondAnchor = i+2 < t->particles.size() ? ((Particle*)t->particles.at( i+2 ))->mPos : secondPoint;

		//float springStretch = 2.5f/t->springs.at( i ).stretch();
		Spring* s = (Spring*)t->springs.at( i );
		float springStretch = 2.5 * s->restLength /s->currentLength();

		glLineWidth( (float)((springStretch + lastStretch)/1.0f) );	// smooth out the changes in stroke width with filter
		lastStretch = springStretch;

		ofCurve( firstAnchor.x, firstAnchor.y,
			firstPoint.x, firstPoint.y,
			secondPoint.x, secondPoint.y,
			secondAnchor.x, secondAnchor.y );
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if ( key == ' ' )
	{
		tendrils.clear();
		physics->clear();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	m->mPos.set(x, y, 0);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	m->mPos.set(x, y, 0);

	tendrils.back().addPoint( ofVec3f(x, y, 0 ) );
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	m->mPos.set(x, y, 0);

	drawing = true;

	tendrils.push_back( T3ndril(physics, ofVec3f(x, y, 0), m) );
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	drawing = false;
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