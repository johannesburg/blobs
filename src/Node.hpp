//
//  Node.hpp
//  blobShaper
//
//  Created by Johan Michalove on 2/5/19.
//

#ifndef Node_hpp
#define Node_hpp

#include "ofMain.h"

class Node {
    float _g = -0.0;
    float _damp = 0.9995;
//    float _damp = 1.0;
    ofVec2f _pos;
    ofVec2f _vel;
    float _mass;
    
    public:
        Node(float x, float y, float m);
        void update();
        void draw();
        ofVec2f getPosition();
        ofVec2f getVelocity();
        void velAdd(ofVec2f v);
};

#endif /* Node_hpp */
