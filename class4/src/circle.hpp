#ifndef circle_hpp
#define circle_hpp

#include "ofMain.h"
#include <stdio.h>
class circle{
    
public:
    circle();
    
    void draw();
    void zenoToPoint(float catchX, float catchY);
    
    ofPoint	pos;
    float catchUpSpeed;
};
#endif /* circle_hpp */
