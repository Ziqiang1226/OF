#include "ofApp.h"
ofFbo fbo;
vector<line> myline;
//line myline;

line::line(){
}

void line::setup(){
    loc = ofPoint(0,0,0);
    weight= ofRandom(1,1.5);
    n= ofRandom(0.1,2);
    
    a=ofRandom(0.2,0.3);
    b=ofRandom(0.3,0.4);
    c=ofRandom(0.4,0.5);
    
    rX = ofRandom(45);
    rY = ofRandom(60);
    rZ = ofRandom(30);
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
}


void line::update(){
    time= ofGetElapsedTimef()*n;

    rX= ofSignedNoise(time*0.3)*400;
    rY= ofSignedNoise(time*0.2)*400;
    rZ= ofSignedNoise(time*0.1)*400;
    
    
    scale= (1-ofNoise(time*0.4))*weight;

    
    moveX= ofSignedNoise(time*a)*ofRandom(7,10);
    moveY= ofSignedNoise(time*b)*ofRandom(7,10);
    moveZ= ofSignedNoise(time*c)*ofRandom(7,10);
    
    loc+= ofPoint(moveX, moveY,moveZ);
}

void line::draw(){
    
    ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    ofScale(scale,scale,scale);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofSetColor(color);
    ofDrawLine(-40,0,40,0);
    ofPopMatrix();
    

}

//--------------------------------------------------------------
void ofApp::setup(){
    //myline.setup();
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();

    for(int i=0; i<5; i++){
        line newline;
        newline.setup();
        myline.push_back(newline);
        
        }
}

//--------------------------------------------------------------
void ofApp::update(){
    //myline.update();
    for(int i=0; i<myline.size(); i++){
        myline[i].update();
        cout << "my Point [" << i << "]: " << myline[i].loc <<endl;


        if(myline[i].loc.y<0||myline[i].loc.y>ofGetWindowHeight()||myline[i].loc.x<0||myline[i].loc.x>ofGetWindowWidth()){
            myline.erase(myline.begin()+i);
            line newline;
            newline.setup();
            myline.push_back(newline);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    //myline.draw();
    ofBackground(255);
    
    fbo.begin();
    
    ofSetColor(255,255,255, 1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for(int i=0; i<myline.size(); i++){
        myline[i].draw();
    }
    
    fbo.end();
    
    ofSetColor(255);
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
