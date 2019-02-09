//
//  Link.hpp
//  blobShaper
//
//  Created by Johan Michalove on 2/3/19.
//

#ifndef Link_hpp
#define Link_hpp

#include "ofMain.h"

class Link {
    int _x, _y;
    int _v;
    int _a;
    int _l;
    float _k;
    vector<Link> _neighbors;

public:
    Link(int x, int y);
    void update();
    void addNeighbor(Link n);
    ofVec2f getPosition();
};

#endif /* Link_hpp */
