//
//  Flow.hpp
//  MusicMidterm
//
//  Created by 何自强 on 2017/3/12.
//
//


#ifndef Flow_hpp
#define Flow_hpp

#include <stdio.h>
#include "ofMain.h"

class flow{
public:
    
    flow();
    void update();
    void draw();
    
    
    ofVec2f pos1;
    ofVec2f pos2;
    ofVec2f vel;
    ofVec2f loc;
    
    float angle;
    float radius;
    float range;
    
    
};





#endif /* Flow_hpp */
