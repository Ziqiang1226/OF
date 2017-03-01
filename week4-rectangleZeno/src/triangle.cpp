

#include "triangle.hpp"


//------------------------------------------------------------------
triangle::triangle(){
    catchUpSpeed = 2;
}

//------------------------------------------------------------------
void triangle::draw() {
    ofFill();
    //ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(240,132,0);
    ofDrawTriangle(pos.x, pos.y-10, pos.x+10, pos.y+10, pos.x-10,pos.y+10);

}

//------------------------------------------------------------------
void triangle::zenoToPoint(float catchX, float catchY){
    
//    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
//    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;

    pos.x = pos.x+(catchX-pos.x)/ofDist(pos.x,pos.y,catchX,catchY);
    pos.y = pos.y+(catchY-pos.y)/ofDist(pos.x,pos.y,catchX,catchY);
    
}
