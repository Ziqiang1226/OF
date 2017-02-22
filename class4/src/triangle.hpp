#ifndef triangle_hpp
#define triangle_hpp

#include "ofMain.h"
#include <stdio.h>
#include "math.h"
class triangle{

public:
    triangle();
    
    void draw();
    void uniformSpeed(float catchX, float catchY);
    
    ofPoint pos;
};
#endif /* traingle_hpp */
