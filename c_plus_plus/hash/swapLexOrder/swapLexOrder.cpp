
typedef std::vector<int> pair_chain_t;
typedef std::unordered_map<int, pair_chain_t > edges_t;
typedef std::vector<std::vector<int> > pairs_t;
typedef std::vector<int> keys_t;
typedef std::set<int> used_set_t;
typedef std::pair<used_set_t::iterator,bool> used_res_t;


// HELPERS
void disp (edges_t edges) {
    cout << "EDGE SIZE: " << edges.size() << endl;
    for ( auto it = edges.begin(); it != edges.end(); ++it ) {
        std::cout << "Key: " << it->first << ": ";
        
        for (int i=0; i<it->second.size();++i)
            cout << it->second[i] << " ";
        
        cout << endl;
    }
    
    cout << endl;
}



// SOLUTION

// Swap characters index by vector
void swap (std::string &str,int src, int selected) {
    char tmp= str[src];
    str[src] =str[selected];
    str[selected] = tmp;
}




// Create a hash for easy look-up of the nodes that can be swapped. (Adjency List)
void build_hash(pairs_t & pairs,edges_t & edges, keys_t & keys ) {
     used_set_t visited;
    for (int i=0;i<pairs.size();++i) {
        int l = pairs[i][0]-1,r = pairs[i][1]-1;
        edges[l].push_back(r);
        edges[r].push_back(l);
        if (visited.insert(l).second == true) keys.push_back(l);
        if (visited.insert(r).second == true) keys.push_back(r);
        
    }
}

 
// Follow the adjancency list, selecting the largest
int traverse_pair_chain(std::string &str,int starting_index,edges_t &edges, used_set_t &used) {
    
    int max = starting_index; 
    int current = starting_index;
    
    // Prime Working Queue with index to the node being swapped too
    std::queue<int> working;
    working.push(starting_index);
    
    // Prime Visited Set with the starting index
    used_set_t visited;
    visited.insert(starting_index);
    
    // Work through entire chain
    while (!working.empty()){
        
        // Get next index in chain to compare
        current =  working.front();
        working.pop();
         
        // Update Max if possikble
        if (str[current]>str[max] && 0 == used.count(current)) {
        
            max = current;
        }
        
        // Add unvisted Children Nodes to processing work queue
        for (int i=0;i<edges[current].size();++i){
           
            if (visited.insert(edges[current][i]).second == true) {           
                // Haven't visted
                working.push(edges[current][i]);
            }
            
        }
    }
    
    // return index of maximum unused character in adjency chain
    return max;   
}




// Returns  str transformed into lexical order based on the swappable pairs,
// by first building a adjency list that allows us to traverse a chain of pairs
// to pick the largest value.  We trarvese left to to right across str, selecting
// the largest unused character in the chain.
std::string swapLexOrder(std::string str,  std::vector<std::vector<int>> pairs ) {
    
    
    edges_t edges;      // Adjanceny list
    keys_t keys;        // Sorted list of keys pointing to the string that will be traversed left-to-right 
    used_set_t used;    // Tracks which characters have been swapped into final position and are now not usable.
    
    // Build Adjaceny Matrix
    build_hash(pairs,edges,keys);
    
    //disp(edges);  // DEBUG
    
    // Sort the Keys
    std::sort(keys.begin(), keys.end());
           
    // Make Lexical Swaps, traversing left
    // to right across swappable characters
    
    for (int i=0;i<keys.size();++i) {
        
        int lrg = traverse_pair_chain(str,keys[i], edges,used);
        
        // Swap Key[i] with it's final value and marked it as used.
        if (keys[i] != lrg) swap(str,keys[i],lrg);
        used.insert(keys[i]);
    }
    
    return str;
}
