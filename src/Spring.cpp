//
//  Spring.cpp
//  blobShaper
//
//  Created by Johan Michalove on 2/5/19.
//

#include "Spring.hpp"
#include "Node.hpp"
#include "ofMain.h"
#include <stdio.h>

Spring::Spring(int n1, int n2, float k, ofColor col) {
    _n1 = n1;
    _n2 = n2;
    _k = k;
    _color = col;
};

void Spring::update(vector<Node> & nodes) {
    ofVec2f diff = nodes[_n1].getPosition() - nodes[_n2].getPosition();
    float dist = diff.length() - (200 * (0.1 * sin(ofGetFrameNum() * 0.02 + 0.8)));
    diff /= diff.length();
    diff *= dist;
    ofVec2f f = diff * _k;
    nodes[_n1].velAdd(-f);
    nodes[_n2].velAdd(f);
};

void Spring::draw(vector<Node> & nodes, ofPolyline & p) {
//    ofSetColor(_color);
//    p.curveTo(ofPoint(_n1.getPosition().x, _n1.getPosition().y), 100);
    p.curveTo(ofPoint(nodes[_n2].getPosition().x, nodes[_n2].getPosition().y), 100);
//    cout << nodes[_n2].getPosition().x << "\n";
}
