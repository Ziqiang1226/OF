#include "ofApp.h"
#include "math.h"

particle arr[300];

//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    string url = "https://api.darksky.net/forecast/5a6b68c5dc45389b85857cd120471d1b/37.8267,-122.4233";
    json.open(url);
    string myString = json["currently"]["summary"].asString();
    cout<<  myString;
    
    play.addListener(this, &ofApp::playPressed);
    stop.addListener(this, &ofApp::stopPressed);
    
    gui.setup();
    gui.add(play.setup("play"));
    gui.add(stop.setup("stop"));
    gui.add(volume.setup("volume",1.0,0.0,1.0));
    gui.add(speed.setup("speed",1.0,-3.0,3.0));
    gui.add(weather.setup(myString));
    
    if(myString!= "rain"){
        soundName= "Dope Arcade - Ascension (MitiS Remix) -Free Download!-.mp3";
    }else{
        soundName= "Secret.mp3";
    }
    soundPlayer.load(soundName);
    soundPlayer.setLoop(true);
    
    //ofSoundSetUseSpectrum(true);
    
    for(int i=0; i<N; i++){
        arr[i].setup();
    }
}

//-----------------------------------------------------------------------------------------
//void ofApp::urlResponse(ofHttpResponse & response){
//    //cout<< 1;
//    if(response.status==200 ){
//        cout << response.request.name << endl;
//        cout << response.data.getText() << endl;
//
//        if (json.parse(response.data.getText())) {  // parse url returns T/F
//            summary = json["daily"]["data"][0]["sunriseTime"].asString();
//            cout << "Summary is:" << summary << endl;
//
//
//        } else {
//            cout << "Parsing Failed." << endl;
//        }
//    }else{
//        cout << response.status << " " << response.error << endl;
//    }
//}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    for(int i=0; i<N; i++){
        arr[i].update();
    }
    myFlow.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<N; i++){
        for(int k=i+1; k<N; k++){
            //if(ofDist(arr[i].pos.x, arr[i].pos.y, ofGetWindowWidth()/2, ofGetWindowHeight()/2)<200){
            arr[i].draw();
            if(ofDist(arr[i].pos.x, arr[i].pos.y, arr[k].pos.x, arr[k].pos.y)<50){
                ofDrawLine(arr[i].pos, arr[k].pos);
            }
            //}
            
        }
    }
    
    float *val= ofSoundGetSpectrum(N);
    //    for(int i=0; i<10; i++){
    //        ofSetColor(255, 255, 255);
    //        ofDrawCircle(850, 650, 30);
    //        double angle=PI/2;
    //        ofDrawRectangle(850+15*cos(angle), 650-15*sin(angle), 3, -val[i]*100);
    //        angle+=PI/6;
    //    }
    
    gui.draw();
    soundPlayer.setVolume(volume);
    soundPlayer.setSpeed(speed);
    
    fbo.begin();
    
    ofSetColor(30,30,30, 10);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    ofSetColor(250, 0, 0);
    
    cout<<arr[0].range<<"\n";
    
    //if(arr[0].range>650){
    myFlow.draw();
    //}
    
    if(myFlow.pos1.x> ofGetWindowWidth()){
        myFlow.pos1.x=0;
        myFlow.pos2.x=0;
    }
    
    fbo.end();
    
    fbo.draw(0,0);
    
}

void ofApp::playPressed(){
    soundPlayer.play();
}

void ofApp::stopPressed(){
    soundPlayer.stop();
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
