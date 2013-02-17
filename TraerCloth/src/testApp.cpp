#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	// system
	physics = new ParticleSystem( 0.0f, 0.0002f );
	physics->clear();

	// generate cloth point
	float gridStepX = (float)( ofGetWidth() * 0.9f / GRID_X_RES );
	float gridStepY = (float)( ofGetHeight() * 0.9f / GRID_Y_RES );
	
	for( int y=0; y<GRID_Y_RES; y++ ){
		for( int x=0; x<GRID_X_RES; x++ ){
			ofVec3f pos = ofVec3f( x * gridStepX + ofGetWidth() * 0.05f, y * gridStepY + 20.0f, 0.0f );
			particles.push_back( physics->makeParticle( 0.2f, pos.x, pos.y, pos.z ) );
			if( x > 0 )
				physics->makeSpring( particles[y*GRID_X_RES + x - 1], particles[y*GRID_X_RES + x], SPRING_STRENGTH, SPRING_DAMPING, gridStepX );
		}
	}

	
	for( int y=1; y<GRID_Y_RES; y++ ){
		for( int x=0; x<GRID_X_RES; x++ ){
			physics->makeSpring( particles[ (y - 1) * GRID_X_RES + x], particles[y*GRID_X_RES + x], SPRING_STRENGTH, SPRING_DAMPING, gridStepY );
		}
	}
	
	int p1i = 0;
	int p2i = GRID_X_RES-1;
	int p3i = (GRID_Y_RES-1)*GRID_X_RES;
	int p4i = (GRID_Y_RES-1)*GRID_X_RES+GRID_X_RES-1;
	
	particles[p1i]->setFixed( true );
	particles[p2i]->setFixed( true );
	particles[p3i]->setFixed( true );
	particles[p4i]->setFixed( true );
	
	particles[p1i]->setLocked( true );
	particles[p2i]->setLocked( true );
	particles[p3i]->setLocked( true );
	particles[p4i]->setLocked( true );
	
	particles[p1i]->mPos.set( 0.0f, 0.0f, 0.0f );
	particles[p2i]->mPos.set( ofGetWidth(), 0.0f, 0.0f );
	particles[p3i]->mPos.set( 0.0f, ofGetHeight(), 0.0f );
	particles[p4i]->mPos.set( ofGetWidth(), ofGetHeight(), 0.0f );

	// gravity
	gravityDir = ofVec3f( 0.0, 0.05, 0.0);
}

//--------------------------------------------------------------
void testApp::update(){
	// 
	physics->setGravity( gravityDir.x, gravityDir.y, gravityDir.z );
    physics->tick(); 
}

//--------------------------------------------------------------
void testApp::draw(){

	// draw vertices
    glColor3f(0.63f, 0.63f, 0.63f);
    for ( int i = 0; i < physics->numberOfParticles(); ++i )
    {
        Particle* v = physics->getParticle( i );
		ofCircle( v->mPos, NODE_SIZE/2.0f );
    }
    
    // draw springs 
	ofSetColor(ofColor::black );
    for ( int i = 0; i < physics->numberOfSprings(); ++i )
    {
        Spring* e = physics->getSpring( i );
        Particle* a = e->getOneEnd();
        Particle* b = e->getTheOtherEnd();
        ofLine( a->mPos, b->mPos );    
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
	ofVec2f pos(x, y);
	selectedParticle->mPos.set( pos.x, pos.y, 0);
	selectedParticle->mVel.set( 0.0f, 0.0f, 0.0f );
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	ofVec2f pos(x, y);
	Particle* closest;
	float closestDist = 1000.0f;
		
	vector<Particle*>::iterator it;
	for( it = particles.begin(); it != particles.end(); ++it ){
		float dist = (*it)->mPos.distance( ofVec3f( pos.x, pos.y, 0.0f ) );
			if( dist < closestDist ){
				closestDist = dist;
				closest = (*it);
			}
		}
		
		selectedParticle = closest;
		selectedParticle->setFixed( true );
		selectedParticle->mPos.set( pos.x, pos.y, 0);
		selectedParticle->mVel.set( 0.0f, 0.0f, 0.0f );
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	selectedParticle->setFixed( false );
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