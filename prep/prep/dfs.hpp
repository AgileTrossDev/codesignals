//
//  dfs.hpp
//  prep
//
//  Created by Scott Jackson on 3/18/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef dfs_hpp
#define dfs_hpp

#include <stdio.h>
#include <vector>

namespace DFS {
    class Vertices;
    class Edges;
    
    struct Edges {
        Edges(): dest(nullptr), weight(INT_MIN) {};
        Edges(Vertices* v, int w): dest(v), weight(w){};
        
        int weight;
        Vertices* dest;
    };

    struct Vertices {
        Vertices(int v) : val(v) {};
        Vertices* add_edge(int v, int w);
        void add_edge(Vertices* v, int w);
        std::vector<Edges*> edges;
        int val;
    };
    
    void dfs_path(Vertices &src,Vertices &dest);
}
#endif /* dfs_hpp */
