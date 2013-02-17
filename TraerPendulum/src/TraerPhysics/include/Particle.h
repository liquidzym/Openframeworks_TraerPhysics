#pragma once

#include "ofMain.h"

namespace traer { namespace physics {

class Particle {
  public:
    Particle( const float &m );
	void setLocked( bool b ){ mIsLocked = b; };
	void setFixed( bool b ){ mIsFixed = b; };
	float		mId;
	ofVec3f	mAnchorPos;
    ofVec3f	mPos;
    ofVec3f	mVel;
    ofVec3f	mAcc;
	ofFloatColor	mCol;
	float		mRadius;
    float		mMass, mInvMass;
	float		mShellRadius;
	float		mCharge;
    float		mAge;
    bool		mIsFixed;
	bool		mIsLocked;
    
    void reset();
  
};

} } // namespace traer::physics