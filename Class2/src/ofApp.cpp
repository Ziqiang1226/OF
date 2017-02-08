#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bool state= true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    int a= 430;
    int b= 200;
    int c= 400;
    int d= 515;
    
    ofSetColor(140,140,140);
    ofDrawRectangle(a+8, 123, 90, 200);
    
    
    ofSetColor(120, 120, 120);
    ofDrawRectangle(a-10, 190, 125, 325);
    
    
    ofSetColor(120, 120, 120);
    ofDrawRectangle(c, 515, 40, 150);
    ofDrawRectangle(c+123, 515, 40, 150);
    
    ofSetColor(100, 100, 100);
    ofDrawRectangle(a-10, 515, 125, 150);
    
    ofSetColor(150, 150, 150);
    ofDrawRectangle(ofGetWindowWidth()/2- 40, 63, 20, 60);
    ofDrawTriangle(ofGetWindowWidth()/2- 40, 63, ofGetWindowWidth()/2- 30, 20 ,ofGetWindowWidth()/2- 20, 63);
    
    
    if(state== true){
    
        for(b=200; b<= 250; b+=10){
            for(int i=0; i<=70; i+=10){
                ofSetColor(255, 255, 255);
                ofDrawRectangle(a+15+i, b-70, 7, 4);
            }
        }
    
        for(b=200; b<= 500; b+=10){
            for(int i=0; i<=100; i+=10){
                ofSetColor(255, 255, 255);
                ofDrawRectangle(a+i, b, 7, 4);
            }
        }
    }else{
        for(b=200; b<= 250; b+=10){
            for(int i=0; i<=70; i+=10){
                ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
                ofDrawCircle(a+18+i, b-65, 4, 4);
            }
        }
        
        for(b=200; b<= 500; b+=10){
            for(int i=0; i<=100; i+=10){
                ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
                ofDrawCircle(a+3+i, b, 4, 4);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    state= false;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    state= true;
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
