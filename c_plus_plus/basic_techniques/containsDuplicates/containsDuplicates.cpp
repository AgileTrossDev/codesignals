typedef std::unordered_set<int> dupe_set_t;




bool containsDuplicates(std::vector<int> a) {

    dupe_set_t tracker;
    
    for (int index =0;index<a.size();++index) {
    
        if (tracker.find(a[index]) == tracker.end())
            tracker.insert(a[index]);
        else
            return true;
        
    }
    
    
    return false;
}

