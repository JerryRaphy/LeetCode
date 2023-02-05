class Solution {
public:
    vector<int> findAnagrams(string p, string s) {
        
        
        int n = s.length();
        int m = p.length();
        vector<int> res;
        
        
        if(n > m) return res;
        
        vector<int> freq(26,0);
        for(int i=0 ; i<n ; ++i) freq[s[i] - 'a']++;
        
        vector<int> temp(26,0);
        for(int i=0 ; i<n ; ++i) temp[p[i] - 'a']++;
        
        if(temp == freq) res.push_back(0);
        
        int r = n;
        int l = 0;
        
        while(r < m){
            temp[p[r] - 'a']++;
            temp[p[l] - 'a']--;
            
            if(temp == freq) res.push_back(l + 1);
            l += 1;
            r += 1;
        }
        
        return res;
    }
};