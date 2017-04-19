//
//  Particle.hpp
//  MusicMidterm
//
//  Created by ‰ΩïËá™Âº∫ on 2017/3/12.
//
//


#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class particle{
public:
    particle();
    void setup();
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f loc;
    
    float n= 300;
    
    float radius;
    float range;
    
    float time0= 0;
    
    float colorVel;
    
    float r;
    float g;
    float b;
    
    float R;
    float G;
    float B;
    
    float*val;
};


#endif /* Particle_hpp */


