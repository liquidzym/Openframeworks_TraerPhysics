#pragma once

#include "ofMain.h"

#include "Particle.h"
#include "ParticleSystem.h"

using namespace traer::physics;

class T3ndril
{
public:
	vector<Particle*> particles;
	vector<Spring*> springs;

	ParticleSystem* physics;
	
	T3ndril( ParticleSystem* p, ofVec3f firstPoint, Particle* followPoint )
	{
		physics = p;
		
		Particle* firstParticle = p->makeParticle( 1.0f, firstPoint.x, firstPoint.y, firstPoint.z );
		particles.push_back( firstParticle );
		physics->makeSpring( followPoint, firstParticle, 0.1f, 0.1f, 5 );
	}

	void addPoint( ofVec3f p )
	{
		Particle* thisParticle = physics->makeParticle( 1.0f, p.x, p.y, p.z );
		springs.push_back( physics->makeSpring( particles.back(),
											 thisParticle, 
											 1.0f,
											 1.0f,
											 particles.back()->mPos.distance( thisParticle->mPos ) ) );
		particles.push_back( thisParticle );
	}
};

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

		void drawElastic( T3ndril* t );
		
		ParticleSystem* physics;
		Particle* m;

		float greyer;
		bool drawing;
		bool nothingDrawn;

		vector<T3ndril> tendrils;

};
