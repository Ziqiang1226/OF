#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Flow.hpp"
#include "ofxGui.h"
#include "ofxJSON.h"
#include <iostream>
using namespace std;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void urlResponse(ofHttpResponse & response);
    void playPressed();
    void stopPressed();
    
    ofxJSONElement json;
    
    string summary;
    string soundName= "Dope Arcade - Ascension (MitiS Remix) -Free Download!-.mp3";
    
    ofxPanel gui;
    ofxButton play;
    ofxButton stop;
    ofxFloatSlider volume;
    ofxFloatSlider speed;
    ofxLabel weather;
    
    ofSoundPlayer soundPlayer;
    const int N= 300;
    const int M= 100;
    
    flow myFlow;
    
    ofFbo fbo;
    
};
