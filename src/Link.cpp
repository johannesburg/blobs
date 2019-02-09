//
//  Link.cpp
//  blobShaper
//
//  Created by Johan Michalove on 2/3/19.
//

#include "Link.hpp"
#include "ofMain.h"

Link::Link(int x, int y) {
    _x = x;
    _y = y;
    _a = 0;
    _v = 0;
    _l = 100;
    _k = 10.0;
}

void Link::addNeighbor(Link n) {
    _neighbors.push_back(n);
}

void Link::update() {
    for (Link n : _neighbors) {
        ofVec2f pos = n.getPosition();
        float dist_x = pow((_x - pos.x), 2);
        float dist_y = pow((_y - pos.y), 2);
        float U_x = 0.5 * _k * pow(dist_x - _l, 2);
        float U_y = 0.5 * _k * pow(dist_y - _l, 2);
        
    }
}

ofVec2f Link::getPosition() {
    return ofVec2f(_x, _y);
}
