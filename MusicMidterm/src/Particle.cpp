//
//  Particle.cpp
//  MusicMidterm
//
//  Created by 何自强 on 2017/3/12.
//
//

#include "Particle.hpp"

particle::particle(){
    
}

void particle::setup(){
    loc.set(ofRandom(0,1000), ofRandom(0,1000));
    radius= 3.5;
    range= 600;
    vel.set(0.1,0.1);
    
    colorVel= 0.1;
    
    r=0;
    g=0;
    b=0;
    
}

void particle::update(){
    float*val= ofSoundGetSpectrum(n);
    
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp( dt, 0.0, 0.1);
    time0 = time;
    
    vel.x= ofMap(val[100],0,0.1,0,1);
    vel.y= ofMap(val[100],0,0.1,0,1);
    range= ofMap(val[2],0,1,600,700);
    
    loc.x+= vel.x* dt;
    loc.y+= vel.y* dt;
    pos.x= ofMap(ofSignedNoise(loc.x)*range, -600, 600, 0, ofGetWindowWidth());
    pos.y= ofMap(ofSignedNoise(loc.y)*range, -500, 500, 0, ofGetWindowHeight());
    
    r+= 0.1* dt;
    g+= 0.2* dt;
    b+= 0.3* dt;
    
    R= ofMap(ofSignedNoise(r),-1,1,100,150);
    G= ofMap(ofSignedNoise(g),-1,1,100,200);
    B= ofMap(ofSignedNoise(b),-1,1,100,250);
}

void particle::draw(){
    ofSetColor(R, G, B);
    ofDrawCircle(pos, radius);
    
}

