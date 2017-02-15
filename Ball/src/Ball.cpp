//
//  Ball.cpp
//  Ball
//
//  Created by 何自强 on 2017/2/15.
//
//

#include "Ball.h"

Ball::Ball(){
}

void Ball::setup(){
    x= ofRandom(0, ofGetWidth());
    y= ofRandom(0, ofGetHeight());
    
    speedX= ofRandom(-1, 1);
    speedY= ofRandom(-1, 1);
    
    dim= 20;
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
}

void Ball::update(){
    if(x< 0){
        x= 0;
        speedX*= -1;
    }else if(x> ofGetWidth()){
        x= ofGetWidth();
        speedX*= -1;
    }
    
    
    if(y< 0){
        y= 0;
        speedY*= -1;
    }else if(y> ofGetHeight()){
        y= ofGetHeight();
        speedY*= -1;
    }
    
    x+=5*speedX;
    y+=5*speedY;
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
}
