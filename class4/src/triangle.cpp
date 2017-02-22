#include "triangle.hpp"


triangle::triangle(){

}

void triangle::draw(){
    ofSetColor(255, 100, 13);
    ofFill();
    ofDrawTriangle(pos.x, pos.y, pos.x+ 20, pos.y, pos.x+ 10, pos.y+ 20);
}

void triangle::uniformSpeed(float catchX, float catchY){
    pos.x = pos.x+ (catchX- pos.x)/ ofDist(pos.x, pos.y, catchX, catchY)*2;
    pos.y = pos.y+ (catchY- pos.y)/ ofDist(pos.x, pos.y, catchX, catchY)*2;
}
