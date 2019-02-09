//
//  Blob.hpp
//  blobShaper
//
//  Created by Johan Michalove on 2/6/19.
//

#ifndef Blob_hpp
#define Blob_hpp

#include <stdio.h>
#include "Node.hpp"
#include "ofMain.h"
#include "Spring.hpp"

class Blob {
    float _nodeCount;
    vector <Node> nodes;
    vector <Spring> springs;
    vector <ofPath> lines;
    
    public:
        Blob(float nodeCount, float center_x, float center_y);
        vector<Node> & getNodes();
        void globalUpdate(vector<Node*> & blobNodes);
        void update();
        ofPath draw();
};

#endif /* Blob_hpp */
