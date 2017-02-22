#include "ofApp.h"
#include "ofMain.h"

ofFbo fbo;

//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetVerticalSync(true);
    

    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    myRectangle.pos.x = 50;
    myRectangle.pos.y = 50;
    
    myCircle.pos.x= 20;
    myCircle.pos.y= 20;
    
    myTriangle.pos.x= 30;
    myTriangle.pos.y= 30;
    
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    myRectangle.zenoToPoint(mouseX, mouseY);
    myCircle.zenoToPoint(mouseX, mouseY);
    myTriangle.uniformSpeed(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
        ofSetColor(0,0,0, 10);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        myRectangle.draw();
        myCircle.draw();
        myTriangle.draw();
    fbo.end();
    
    fbo.draw(0,0);
}
