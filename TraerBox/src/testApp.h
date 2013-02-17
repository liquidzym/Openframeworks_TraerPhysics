#pragma once

#include "ofMain.h"

#include "Particle.h"
#include "ParticleSystem.h"
#include "ModifiedEulerIntegrator.h"

#define BIGBOX_SIZE 400
#define LITTLEBOX_SIZE 12
#define NUM_LITTLEBOX 800

using namespace traer::physics;

class testApp : public ofBaseApp{

	public:
		testApp(){}
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
		
		float xRotation, yRotation;

		float bounceDamp;
		float repulsionStrength;
		float repulsionMinimum;
		
		float gravityMagnitude;

		ParticleSystem* physics;
		ModifiedEulerIntegrator* eulerInter;
		
		// rotate global gravity
		void setRotation( float xRotate, float yRotate )
		{
		  physics->setGravity(  
			  gravityMagnitude*sin( xRotate )*sin( yRotate ),
			  gravityMagnitude*cos( xRotate ),
			  -gravityMagnitude*sin( xRotate )*cos( yRotate ) 
		  );
		  xRotation = xRotate;
		  yRotation = yRotate; 
		}

		// bounce collision
		void bounce()
		{
		  float collisionPoint = 0.5*( BIGBOX_SIZE - LITTLEBOX_SIZE );
		  for ( int i = 0; i < physics->numberOfParticles(); i++ )
		  {
			Particle* p = physics->getParticle( i );

			if ( p->mPos.x < -collisionPoint )
			{
			  p->mPos.x =  -collisionPoint;
			  p->mVel.x = -p->mVel.x;
			}
			else
			  if ( p->mPos.x > collisionPoint )
			  {
				p->mPos.x = collisionPoint;
				p->mVel.x = -bounceDamp*p->mVel.x;
			  }

			if ( p->mPos.y < -collisionPoint )
			{
			  p->mPos.y = -collisionPoint ;
			  p->mVel.y = -bounceDamp*p->mVel.y;
			}
			else
			  if ( p->mPos.y > collisionPoint )
			  {
				p->mPos.y = collisionPoint ;
				p->mVel.y = -bounceDamp*p->mVel.y;
			  }

			if ( p->mPos.z < -collisionPoint )
			{
			  p->mPos.z = -collisionPoint ;
			  p->mVel.z = -bounceDamp*p->mVel.z;
			}
			else
			  if ( p->mPos.z > collisionPoint )
			  {
				p->mPos.z =  collisionPoint ;
				p->mVel.z = -bounceDamp*p->mVel.z;
			  }
		  } 
		}
};
