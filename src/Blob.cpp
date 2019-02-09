//
//  Blob.cpp
//  blobShaper
//
//  Created by Johan Michalove on 2/6/19.
//

#include "Blob.hpp"
#include "Spring.hpp"
#include "Node.hpp"
#include "ofMain.h"

Blob::Blob(float nodeCount, float center_x, float center_y) {
    _nodeCount = nodeCount;
    for (int i = 0; i < nodeCount; i++) {
        float ang = i / nodeCount * 2 * PI;
        float circ = (nodeCount * 20) / (2 * PI);
        float x = ofGetWidth() / 2.0  + (cos(ang) * circ) + center_x;
        float y = ofGetHeight() / 2.0 + (sin(ang) * circ) + center_y;
        Node n = Node(x, y, 1.0);
        nodes.push_back(n);
    }
    for (int i = 0; i < nodes.size()-1; i++) {
        ofColor col = ofColor(255, 255, 255);
        Spring s = Spring(i, i+1, 0.001, col);
        springs.push_back(s);
    }
    Spring s = Spring(nodes.size()-1, 0, 0.001, ofColor(255, 255, 255));
    springs.push_back(s);
};

vector<Node> & Blob::getNodes() {
    return nodes;
}

void Blob::update() {
    
//    for (int i = 0; i < nodes.size(); i++) {
//        Node a = nodes[i];
//        for (int j = i + 1; j < nodes.size(); j++) {
//            Node b = nodes[j];
//            ofVec2f diff = a.getPosition() - b.getPosition();
//            float mag = abs(diff.length());
//            diff = diff * (0.02 / (mag * mag * mag + 3.0));
//            nodes[i].velAdd(diff);
//            nodes[j].velAdd(-diff);
//        }
//    }
    
    for (int i = 0; i < nodes.size(); i++) {
        Node a = nodes[i];
        ofVec2f diff = a.getPosition() - ofVec2f(ofGetMouseX(), ofGetMouseY());
        
        float mag = abs(diff.length());
        diff = diff * (1.0 / (mag * mag * mag + 128.0 ));
        
        nodes[i].velAdd(diff);
        
        diff = a.getPosition() - ofVec2f((ofGetWidth() / 2.0) + 100.0 * cos(ofGetFrameNum() * 0.002), (ofGetHeight() / 2.0) + 50.0 * sin(ofGetFrameNum() * 0.006));
        mag = abs(diff.length());
        diff = diff * (0.00009 / (mag + 128.0));
        nodes[i].velAdd(-diff);
    }
    
    for (int i = 0; i < springs.size(); i++) {
        springs[i].update(nodes);
    }

    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].update();
    }
}

ofPath Blob::draw() {
    ofPolyline blob;
    Spring s = springs[springs.size()-1];
    blob.curveTo(ofPoint(nodes[s._n1].getPosition().x, nodes[s._n1].getPosition().y), 100);
    s = springs[0];
    blob.curveTo(ofPoint(nodes[s._n1].getPosition().x, nodes[s._n1].getPosition().y), 100);
    for (int i = 0; i < springs.size(); i++) {
        springs[i].draw(nodes, blob);
    }
    blob.curveTo(ofPoint(nodes[s._n1].getPosition().x, nodes[s._n1].getPosition().y), 100);
    //    blob.curveTo(ofPoint(nodes[0].getPosition().x, nodes[0].getPosition().y), 100);
    ofSetLineWidth(2.0);
    //    ofFill();
    //    ofSetColor(255, 255, 255);
    //    blob.close();
    
    ofPath path;
    
    for( int i = 0; i < blob.getVertices().size(); i++) {
        if(i == 0) {
            path.newSubPath();
            path.moveTo(blob.getVertices()[i] );
        } else {
            path.lineTo(blob.getVertices()[i] );
        }
    }
    
    path.simplify();
    path.setFillColor(ofColor(0, 0, 0));
    path.setStrokeColor(ofColor(255, 255, 255, 100));
    path.setStrokeWidth(3.0);
    path.setFilled(true);
    return path;
}

void Blob::globalUpdate(vector<Node*> & blobNodes) {
    for (int i = 0; i < blobNodes.size()-1; i++) {
        Node a = *blobNodes[i];
        for (int j = i + 1; j < blobNodes.size(); j++) {
            Node b = *blobNodes[j];
            ofVec2f diff = a.getPosition() - b.getPosition();
            float mag = abs(diff.length());
            diff = diff * (0.02 / (mag * mag * mag + 2.0));
            blobNodes[i]->velAdd(diff);
            blobNodes[j]->velAdd(-diff);
        }
    }
}
