//
//  Flow.cpp
//  MusicMidterm
//
//  Created by 何自强 on 2017/3/12.
//
//


#include "Flow.hpp"
#include "ofApp.h"

flow:: flow(){
    radius=4;
    vel.set(20,0);
    pos1.set(100,700);
    pos2.set(100,700);
}

void flow::update(){
    
    pos1+= vel;
    pos2+= vel;
    pos1.y= sin(pos1.x/10)*10+700;
    pos2.y= cos(pos2.x/10)*10+700;
}

void flow::draw(){
    ofDrawCircle(pos1,radius);
    ofDrawCircle(pos2,radius);
}

