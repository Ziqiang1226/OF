#include "circle.hpp"

circle::circle(){
    catchUpSpeed= 0.01f;
}

void circle::draw(){
    ofSetColor(251, 44, 19);
    ofFill();
    ofDrawCircle(pos.x, pos.y, 10);
}

void circle::zenoToPoint(float catchX, float catchY){
    pos.x= catchUpSpeed* catchX+ (1- catchUpSpeed)* pos.x;
    pos.y= catchUpSpeed* catchY+ (1- catchUpSpeed)* pos.y;
}
