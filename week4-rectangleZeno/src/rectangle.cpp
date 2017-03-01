#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.01f;
    
}

//------------------------------------------------------------------
void rectangle::draw() {
    
    
    ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(118,189,34);
    ofDrawRectangle(pos.x, pos.y, 20,20);
    
    ofNoFill();
    ofSetColor(100,100,100);
    ofDrawRectangle(400, 400, 400, 400);
}

//------------------------------------------------------------------
void rectangle::zenoToPoint(float catchX, float catchY){
    
    if(catchX>200 && catchX<600 && catchY>200 && catchY<600){
    
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
        
    } else {
        pos.x = pos.x+(catchX-pos.x);
        pos.y = pos.y+(catchY-pos.y);
    }
    
    
}
