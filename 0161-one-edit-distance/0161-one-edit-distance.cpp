class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        if(abs(n - m) >= 2) return false;
        bool ops = false;
        
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(s[i] != t[j]){
                ops = true;
                
                // replace
                if(s.substr(i+1) == t.substr(j+1)) return true; 
                
                // insert
                if(s.substr(i) == t.substr(j+1)) return true;
                
                // delete
                if(s.substr(i+1) == t.substr(j)) return true;
                
                return false;
            }
            i += 1;
            j += 1;
        }
        
        if(!ops && j == m && i == n - 1) return true;
        if(!ops && i == n && j == m - 1) return true;
        if(!ops) return false;
        return true;
    }
};