#pragma once

#include "ofMain.h"

#include "ParticleSystem.h"
#include "Particle.h"
#include "ModifiedEulerIntegrator.h"
#include "Spring.h"

using namespace traer::physics;

#define NODE_SIZE 10
#define SPRING_STRENGTH 0.1
#define SPRING_DAMPING 0.01
#define GRID_X_RES 15
#define GRID_Y_RES 20

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
		
		ParticleSystem*		physics;
		vector<Particle*>	particles;

		Particle*			selectedParticle;

		ofVec3f				gravityDir;

};
