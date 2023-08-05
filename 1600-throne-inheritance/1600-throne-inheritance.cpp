class ThroneInheritance {
public:
    
    map<string,vector<string>> mp;
    set<string> dead;
    string king;
    
    ThroneInheritance(string kingName) {
        king = kingName;
        dead.clear();
        mp.clear();
    }
    
    void birth(string parent, string child) {
        mp[parent].push_back(child);
    }
    
    void death(string name) {
         dead.insert(name);
    }
    
    void getinheritance(string parent, vector<string> &inheritance){
        
        if(!dead.count(parent)) inheritance.push_back(parent);
        
        for(auto child : mp[parent]){
            getinheritance(child,inheritance);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> inheritance;
        getinheritance(king,inheritance);
        return inheritance;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */