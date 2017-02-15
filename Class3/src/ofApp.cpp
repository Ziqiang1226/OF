#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
//    if(myX> ofGetWidth() || myX<0){
//        pxOffset= pxOffset* -1;
//        }
//    myX+= pxOffset;
}

//--------------------------------------------------------------
void ofApp::draw(){
    int deltaX= ofMap(mouseX, 0, ofGetWidth(), 0, 50);
    int deltaY= ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    for(int y=0; y<ofGetHeight(); y+=20+deltaY){
        for(int x=0; x<ofGetWidth(); x+=20+deltaX){
            int mouseDistX= abs(x- mouseX);
            int mouseDistY= abs(y- mouseY);
            int colorOffset= 0;
            if(mouseDistX< 100 && mouseDistY< 100){
                colorOffset= 100+ mouseDistX+ mouseDistY;
            }
            ofSetColor(colorOffset, x/5+y/5, 225);
            ofDrawCircle(x,y,10);
        }
    }
    //ofDrawCircle(myX, myY, 10);
        
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if(key== 'w'){
//        myY-=10;
//    }else if(key== 's'){
//        myY+=10;
//    }else if(key== ' '){
//        pxOffset= pxOffset* -1;
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
//    if(key== 't'){
//        ofLog(OF_LOG_NOTICE, "Char Pressed: t");
//    }else if(key== 'q'){
//        ofLog(OF_LOG_NOTICE, "Char Pressed: q");
//    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseX= x;
    mouseY= y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
