//
//  Node.cpp
//  blobShaper
//
//  Created by Johan Michalove on 2/5/19.
//

#include "Node.hpp"

Node::Node(float x, float y, float m) {
    _pos = ofVec2f(x, y);
    _vel = ofVec2f(0, 0);
    _mass = m;
}

void Node::draw() {
    // Does nothing atm
}

void Node::update() {
    _pos = _pos + _vel;
    _vel = _vel * _damp;
    _vel.y += _g;
}

ofVec2f Node::getPosition() {
    return _pos;
}

ofVec2f Node::getVelocity() {
    return _vel;
}

void Node::velAdd(ofVec2f v) {
    _vel = _vel + v;
}
