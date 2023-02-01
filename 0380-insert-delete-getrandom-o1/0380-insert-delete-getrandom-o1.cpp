class RandomizedSet {
public:
    
    vector<int> v;
    unordered_map<int,int> mp;
    int idx;
    
    RandomizedSet() {
        mp.clear();
        v.clear();
        idx = 0;
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        
        v.push_back(val);
        mp[val] = idx;
        idx += 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        
        // else we will swap the current index with the last index 
        int index_of_val = mp[val];
        int last_index = idx - 1;
        
        swap(v[index_of_val],v[last_index]);
        mp[v[index_of_val]] = index_of_val;
        
        mp.erase(val);
        v.pop_back(); 
        idx -= 1;
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */