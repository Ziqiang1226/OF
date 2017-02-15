//
//  Ball.h
//  Ball
//
//  Created by 何自强 on 2017/2/15.
//
//

#ifndef Ball_h
#define Ball_h

#include "ofMain.h"

    class Ball{

        public:
    
        void setup();
        void update();
        void draw();
    
        float x;
        float y;
        float speedX;
        float speedY;
        int dim;
        ofColor color;
    
    
        Ball();
    private:
    
    };

#endif
