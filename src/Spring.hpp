//
//  Spring.hpp
//  blobShaper
//
//  Created by Johan Michalove on 2/5/19.
//

#ifndef Spring_hpp
#define Spring_hpp

#include "ofMain.h"
#include "Node.hpp"

class Spring {
    float _k;
    ofColor _color;
    
    public:
        int _n1;
        int _n2;
        Spring(int n1, int n2, float k, ofColor col);
        void update(vector<Node> & nodes);
        void draw(vector<Node> & nodes, ofPolyline &p);
    
};

#endif /* Spring_hpp */
