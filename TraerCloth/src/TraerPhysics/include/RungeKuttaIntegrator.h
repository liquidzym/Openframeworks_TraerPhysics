#pragma once

#include <vector>
#include "ofMain.h"
#include "Integrator.h"
#include "ParticleSystem.h"

namespace traer { namespace physics {

class RungeKuttaIntegrator : public Integrator
{

public:

	std::vector<ofVec3f> originalPositions;
	std::vector<ofVec3f> originalVelocities;
	std::vector<ofVec3f> k1Forces;
	std::vector<ofVec3f> k1Velocities;
	std::vector<ofVec3f> k2Forces;
	std::vector<ofVec3f> k2Velocities;
	std::vector<ofVec3f> k3Forces;
	std::vector<ofVec3f> k3Velocities;
	std::vector<ofVec3f> k4Forces;
	std::vector<ofVec3f> k4Velocities;
	
	ParticleSystem* s;
	
	RungeKuttaIntegrator( ParticleSystem* s );
	
	void allocateParticles();
	
	void step( const float &deltaT );

};

} } // namespace traer::physics