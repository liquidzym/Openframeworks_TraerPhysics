#pragma once

#include "ofMain.h"

#include <float.h>  

#include "Particle.h"
#include "ParticleSystem.h"

#define NODE_SIZE 10
#define EDGE_LENGTH 20
#define EDGE_STRENGTH 0.2
#define SPACER_STRENGTH 1000

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
		
		ParticleSystem* physics;

		float centroidX, centroidY;
		float scale;

		float width, height;
		
		void initialize()
		{
		  physics->clear();
		  physics->makeParticle();
		}

		void addNode()
		{ 
		  Particle* p = physics->makeParticle();
		  Particle* q = physics->getParticle( (int)ofRandom( 0, physics->numberOfParticles()-1) );
		  while ( q == p )
			q = physics->getParticle( (int)ofRandom( 0, physics->numberOfParticles()-1) );
		  addSpacersToNode( p, q );
		  makeEdgeBetween( p, q );
		  p->mPos.set( q->mPos.x + ofRandom( -1, 1 ), q->mPos.y + ofRandom( -1, 1 ), 0 );
		}

		void makeEdgeBetween( Particle* a, Particle* b )
		{
		  physics->makeSpring( a, b, EDGE_STRENGTH, EDGE_STRENGTH, EDGE_LENGTH );
		}

		void addSpacersToNode( Particle* p, Particle* r )
		{
		  for ( int i = 0; i < physics->numberOfParticles(); ++i )
		  {
			Particle* q = physics->getParticle( i );
			if ( p != q && p != r )
			  physics->makeAttraction( p, q, -SPACER_STRENGTH, 20 );
		  }
		}

		// calculate particles centroid & scale 
		void updateCentroid()
		{
		  float 
			xMax = FLT_MIN, 
			xMin = FLT_MAX, 
			yMin = FLT_MAX, 
			yMax = FLT_MIN;

		  for ( int i = 0; i < physics->numberOfParticles(); ++i )
		  {
			Particle* p = physics->getParticle( i );
			xMax = max( xMax, p->mPos.x );
			xMin = min( xMin, p->mPos.x );
			yMin = min( yMin, p->mPos.y );
			yMax = max( yMax, p->mPos.y );
		  }
		  float deltaX = xMax-xMin;
		  float deltaY = yMax-yMin;
  
		  centroidX = xMin + 0.5*deltaX;
		  centroidY = yMin +0.5*deltaY;
  
		  // compute scale, avoid screen out
		  if ( deltaY > deltaX )
			scale = height/(deltaY+50);
		  else
			scale = width/(deltaX+50);
		}
};
