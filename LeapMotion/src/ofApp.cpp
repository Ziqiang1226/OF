#include "ofApp.h"

//--------------------------------------------------------------

// relative point list  (starting at origin)
ofPoint pBot = ofPoint(0, 0);  // start
ofPoint pRi = ofPoint(50, 0); // go up and right
//ofPoint pLe = ofPoint(50, -50);  // go up and left
//ofPoint pTop = ofPoint(-50, -50); // go down and left
//ofPoint pEnd = ofPoint(-50, 50);  // go down and right   it's a circle!
ofPoint gPoints[] = {pBot, pRi};

ofImage img[100];
int n= 0;

simpleGesture gesture;

void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //ofSetLogLevel(OF_LOG_VERBOSE);
    
    leap.open();
    
    cam.setOrientation(ofPoint(-20, 0, 0));
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    gesture.setup(gPoints, 4, 2000);
    
    for(int i=0; i<3; i++){
        img[i].load(to_string( i+1 ) +".jpg");
    }
    
}


//--------------------------------------------------------------
void ofApp::update(){
    fingersFound.clear();
    
    //here is a simple example of getting the hands and drawing each finger and joint
    //the leap data is delivered in a threaded callback - so it can be easier to work with this copied hand data
    
    //if instead you want to get the data as it comes in then you can inherit ofxLeapMotion and implement the onFrame method.
    //there you can work with the frame data directly.
    
    
    
    //Option 1: Use the simple ofxLeapMotionSimpleHand - this gives you quick access to fingers and palms.
    
    
    simpleHands = leap.getSimpleHands();
    
    if( leap.isFrameNew() && simpleHands.size() ){
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        /*
         for(int i = 0; i < simpleHands.size(); i++){
         for (int f=0; f<5; f++) {
         int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
         ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
         ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
         ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
         ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip
         fingersFound.push_back(id);
         }
         }
         */
    }
    
    
    
    //Option 2: Work with the leap data / sdk directly - gives you access to more properties than the simple approach
    //uncomment code below and comment the code above to use this approach. You can also inhereit ofxLeapMotion and get the data directly via the onFrame callback.
    /*
     vector <Hand> hands = leap.getLeapHands();
     if( leap.isFrameNew() && hands.size() ){
     
     //leap returns data in mm - lets set a mapping to our world space.
     //you can get back a mapped point by using ofxLeapMotion::getMappedofPoint with the Leap::Vector that tipPosition returns
     leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
     leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
     leap.setMappingZ(-150, 150, -200, 200);
     
     fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
     
     for(int i = 0; i < hands.size(); i++){
     for(int j = 0; j < 5; j++){
     ofPoint pt;
     
     const Finger & finger = hands[i].fingers()[ fingerTypes[j] ];
     
     //here we convert the Leap point to an ofPoint - with mapping of coordinates
     //if you just want the raw point - use ofxLeapMotion::getofPoint
     pt = leap.getMappedofPoint( finger.tipPosition() );
     pt = leap.getMappedofPoint( finger.jointPosition(finger.JOINT_DIP) );
     
     fingersFound.push_back(finger.id());
     }
     }
     }
     */
    
    //IMPORTANT! - tell ofxLeapMotion that the frame is no longer new.
    leap.markFrameAsOld();
}


// define your gesture
void simpleGesture::setup(ofPoint *points, int maxIndex, int msTout){
    gPts = points;
    maxIdx = maxIndex;
    timeout = msTout;
    curIdx = 1;
}

// Give a moving input point.  Returns true if gesture matched.
bool simpleGesture::track (ofPoint iPt) {
    bool xMatch = false, yMatch = false;
    int timePerPoint = timeout / maxIdx;
    
    int currentT = ofGetElapsedTimeMillis();
    if (currentT > stepStartTime + timePerPoint) {
        curIdx = 1;
        lastPoint = iPt;
        stepStartTime = currentT;
    }
    
    // where to go next abs screen coords
    ofPoint absNext = lastPoint + gPoints[curIdx];
    
    if (gPoints[curIdx-1].x == gPoints[curIdx].x) {  // if nothing has changed, match.
        xMatch = true;
    }
    
    if (gPoints[curIdx-1].y == gPoints[curIdx].y) {  // if nothing has changed, match.
        yMatch = true;
    }
    
    // find out what direction we are heading in
    if (gPoints[curIdx-1].x < gPoints[curIdx].x) {  // going right
        if (absNext.x < iPt.x)			// have we exceeded that x?
            xMatch = true;
    } else {					// going left
        if (absNext.x > iPt.x)
            xMatch = true;
    }
    
    if (gPoints[curIdx-1].y < gPoints[curIdx].y) {  // going down
        if (absNext.y < iPt.y) 			// have we exceeded that y?
            yMatch = true;
    } else {					// going up
        if (absNext.y > iPt.y)
            yMatch = true;
    }
    
    // if we have x & y
    if (xMatch && yMatch) {
        curIdx++;
        lastPoint = iPt;
        stepStartTime = currentT;
        
        if (curIdx == maxIdx) {  // if we just matched our last point
            // cout << "Matched" << endl;  // debug
            curIdx = 1; // start from beginning
            return(true);
        }
    }
    
    // cout << iPt.x << " " << iPt.y << " " << curIdx << endl;  // debug
    return (false);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofBackgroundGradient(ofColor(90, 90, 90), ofColor(30, 30, 30),  OF_GRADIENT_BAR);
    
    
    ofSetColor(200);
    ofDrawBitmapString("ofxLeapMotion - Example App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);
    
    cam.begin();
    img[n].draw(-ofGetWindowWidth()/2,-ofGetWindowHeight()/2,ofGetWindowWidth(),ofGetWindowHeight());
    
    ofPushMatrix();
    ofRotate(90, 0, 0, 1);
    ofSetColor(20);
    ofDrawGridPlane(800, 20, false);
    ofPopMatrix();
    
    
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        ofPoint handNormal = simpleHands[i].handNormal;
        
        ofSetColor(0, 0, 255);
        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
        ofSetColor(255, 255, 0);
        ofDrawArrow(handPos, handPos + 100*handNormal, 20);
        
        // Give simple gesture more data and get return value
        bool gDone = gesture.track(simpleHands[0].fingers[INDEX].tip);  // send index finger tip
        if (gDone){
            cout << "----------------------GOT IT----------------------" << endl;
            cout <<n<<endl;
            n++;
            if(n>=3){
                n=0;
            }
        }
        
        
        
        
        for (int f=0; f<5; f++) {
            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
            
            ofSetColor(0, 255, 0);
            ofDrawSphere(mcp.x, mcp.y, mcp.z, 12);
            ofDrawSphere(pip.x, pip.y, pip.z, 12);
            ofDrawSphere(dip.x, dip.y, dip.z, 12);
            ofDrawSphere(tip.x, tip.y, tip.z, 12);
            
            ofSetColor(255, 0, 0);
            ofSetLineWidth(20);
            ofLine(mcp, pip);
            ofLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
            ofLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
        }
    }
    cam.end();
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    // let's close down Leap and kill the controller
    leap.close();
}
