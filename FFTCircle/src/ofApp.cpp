#include "ofApp.h"

particle arr[300];
//--------------------------------------------------------------
void ofApp::setup(){
    song.load("Dope Arcade - Ascension (MitiS Remix) -Free Download!-.mp3");
    while(!song.isLoaded());
    song.play();
    nBandsToGet= 512;
    
    for(int i=0; i<N; i++){
        arr[i].setup();
    }
    
    smooth = new float[8192];
    for (int i = 0; i < 8192; i++){
        smooth[i] = 0;
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0x23, 0x32, 0x37);
    val= ofSoundGetSpectrum(nBandsToGet);
    
    for(int i=0; i< nBandsToGet; i++){
        smooth[i]*=0.96;
        if (smooth[i] < val[i]) smooth[i] = val[i];
    }
    
    if(val[10]<0.4){
        for(int i=0; i<N; i++){
            arr[i].update();
        }
    }


    
}

float getX(int deg, int radius){
    float x= radius* cos(ofDegToRad(deg))+ ofGetWindowWidth()/2;
    return(x);
}

float getY(int deg, int radius){
    float y= radius* sin(ofDegToRad(deg))+ ofGetWindowHeight()/2;
    return(y);
}

//--------------------------------------------------------------
void ofApp::draw(){
    int r= 100;
    ofSetColor(0x98, 0x4b, 0x43, 255);
    
    if(val[0]>0.8){
        for(int i=0; i<nBandsToGet; i++){
            float x1= getX(i, r);
            float y1= getY(i, r);
            float x2= getX(i, r+ 500* smooth[i/5]);
            float y2= getY(i, r+ 500* smooth[i/5]);
            
            //ofDrawLine(x1, y1, x2, y2);
            ofDrawCircle(x2, y2, 2);
        }
    }

    
    for(int i=0; i<N; i++){
        for(int k=i+1; k<N; k++){
            if(ofDist(arr[i].pos.x, arr[i].pos.y, ofGetWindowWidth()/2, ofGetWindowHeight()/2)<200){
                arr[i].draw();
                if(ofDist(arr[i].pos.x, arr[i].pos.y, arr[k].pos.x, arr[k].pos.y)<15){
                ofDrawLine(arr[i].pos, arr[k].pos);
                }
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
