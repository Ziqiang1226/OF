#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
    catchUpSpeed = 0.01f;
}

//------------------------------------------------------------------
void rectangle::draw() {
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, 20,20);
}

//------------------------------------------------------------------
void rectangle::zenoToPoint(float catchX, float catchY){
    pos.x = pos.x+ (catchX- pos.x)/ ofDist(pos.x, pos.y, catchX, catchY)* catchX;
    pos.y = pos.y+ (catchY- pos.y)/ ofDist(pos.x, pos.y, catchX, catchY)* catchY;
}

