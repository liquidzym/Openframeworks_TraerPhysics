#pragma once

#include "ofMain.h"

#include "Particle.h"
#include "ParticleSystem.h"

using namespace traer::physics;

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void handleBoundaryCollisions( Particle* p )
		{
			float width = ofGetWidth();
			float height = ofGetHeight();
			if ( p->mPos.x < 0 || p->mPos.x > width )
				p->mVel.set( -0.9*p->mVel.x, p->mVel.y, 0 );
			if ( p->mPos.y < 0 || p->mPos.y > height )
				p->mVel.set( p->mVel.x, -0.9*p->mVel.y, 0 );
			p->mPos.set( ofClamp( p->mPos.x, 0, width ), ofClamp( p->mPos.y, 0, height ), 0 ); 
		}
		
		ParticleSystem* physics;
		Particle *mpart, *mb, *mc;
		

};
