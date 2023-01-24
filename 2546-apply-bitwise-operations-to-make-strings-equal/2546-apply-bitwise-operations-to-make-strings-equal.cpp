class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        int n = s.length();
        if(s == target) return true;
        
        bool f1 = false;
        bool f2 = false; 
        
        for(int i=0 ; i<n ; ++i){
            if(s[i] == '1') f1 = true;
            if(target[i] == '1') f2 = true;
        }
        
        if(f1 && f2) return true;
        return false;
        
    }
};