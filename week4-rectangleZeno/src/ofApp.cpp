#include "ofApp.h"
#include "ofMain.h"

ofFbo fbo,spFbo;
//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

	// set the position of the rectangle:
	myRectangle.pos.x = 100;
	myRectangle.pos.y = 50;
    
    myCircle.pos.x = 100;
    myCircle.pos.y = 100;
    
    myTriangle.pos.x = 100;
    myTriangle.pos.y = 150;
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    spFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    spFbo.begin();
    ofClear(255,255,255, 0);
    spFbo.end();
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
	myRectangle.zenoToPoint(mouseX, mouseY);
    myCircle.zenoToPoint(mouseX, mouseY);
    myTriangle.zenoToPoint(mouseX,mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
	
    
    fbo.begin();
    ofSetColor(30,30,30, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    myRectangle.draw();
    myCircle.draw();
    myTriangle.draw();
    fbo.end();
    
    spFbo.begin();
    ofSetColor(255,255,255);
    fbo.draw(10, 10, ofGetWidth()-20, ofGetHeight()-20);
    spFbo.end();
    
    fbo = spFbo;
    
    ofSetColor(255,255,255);
    fbo.draw(0,0);
    
    

}
