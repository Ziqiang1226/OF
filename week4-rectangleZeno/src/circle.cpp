#include "circle.hpp"


//------------------------------------------------------------------
circle::circle(){
    catchUpSpeed = 0.03f;
}

//------------------------------------------------------------------
void circle::draw() {

    ofFill();
    //ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(250,54,74);
    ofDrawCircle(pos.x, pos.y, 10);
    
}

//------------------------------------------------------------------
void circle::zenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
