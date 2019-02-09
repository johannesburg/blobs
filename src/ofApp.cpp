#include "ofApp.h"
#include "Node.hpp"
#include "Spring.hpp"
#include "Blob.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(100);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetWindowTitle("color example");
    ofSetBackgroundAuto(false);

    ofSetRectMode(OF_RECTMODE_CENTER);
    
//    ofSetFrameRate(2); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    int numBlobs = 15;
    for (int i = 0; i < numBlobs; i++) {
        Blob b = Blob(20, -20 * (i + 1), 0);
        blobs.push_back(b);
        vector<Node> & nodes = blobs[i].getNodes();
        for (int i = 0; i < nodes.size(); i++) {
            blobNodes.push_back(&nodes[i]);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    int simSteps = 15;
    for (int sim = 0; sim < simSteps; sim++) {
        blobs[0].globalUpdate(blobNodes);
        for (int i = 0; i < blobs.size(); i++) {
            blobs[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if( ofGetFrameNum() == 1 )
    {
        ofSetWindowPosition( ofGetWindowPositionX(), ofGetWindowPositionY()+1 );
        ofSetWindowPosition( ofGetWindowPositionX(), ofGetWindowPositionY()-1 );
    }
    ofBackground(0, 1.0);
    ofSetLineWidth(2.0);
    ofSetColor(255, 255, 255);
    ofFill();
    for (int i = 0; i < blobs.size(); i++) {
        ofPath path = blobs[i].draw();
        lines.push_back(path);
    }
    
    float scale = -0.2 * sin(0.008 * ofGetFrameNum()) + -0.3;
    //    ofPushMatrix();
    ofTranslate(0, -scale * lines.size());
    for (int i = 0; i < lines.size() ; i++) {
        lines[i].draw();
        ofTranslate(0, scale);
    }
    //    ofPopMatrix();
    
    while (lines.size() > 1400) {
        lines.erase(lines.begin());
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
