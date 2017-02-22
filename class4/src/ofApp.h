#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "rectangle.h"
#include "circle.hpp"
#include "triangle.hpp"

class ofApp : public ofSimpleApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    rectangle myRectangle;
    circle myCircle;
    triangle myTriangle;
};

#endif
