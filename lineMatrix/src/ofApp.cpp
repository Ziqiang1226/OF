#include "ofApp.h"
ofFbo fbo;
//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
    
    fbo.begin();
        ofClear(255,255,255,0);
    fbo.end();

}

//--------------------------------------------------------------
void ofApp::update(){
    float time= ofGetElapsedTimef();
    rX= ofSignedNoise(time*0.5)*380;
    rY= ofSignedNoise(time*0.3)*380;
    rZ= ofSignedNoise(time*0.7)*380;
    
    scaleX= 1-ofNoise(time*0.2);
    scaleY= 1-ofNoise(time*0.4);
    scaleZ= 1-ofNoise(time*0.6);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);

    fbo.begin();
    
    ofSetColor(255,255,255, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofScale(scaleX,scaleY,scaleZ);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofSetColor(0);
    ofDrawLine(-20, 500, 20, 500);
    ofPopMatrix();
    
    fbo.end();

    
    fbo.draw(0,0);

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
