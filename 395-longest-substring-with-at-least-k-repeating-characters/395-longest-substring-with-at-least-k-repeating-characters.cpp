class Solution {
public:
    
    int getlongest(int st, int en, string s, int k){
        if(st > en) return 0;
        
        vector<int> v(26,0);
        for(int i=st ; i<=en ; ++i){
            v[s[i] - 97]++;
        }    
        
        int f = st;
        int i = st;
        int res = 0;
        
        while(i <= en){
            if(v[s[i] - 97] < k){
                res = max(res,getlongest(f,i-1,s,k));
                f = i+1; 
            }
            i++;
        }
        
        if(f == st) return en - st + 1;
        res = max(res,getlongest(f,i-1,s,k));
        return res;
    }
    
    
    int longestSubstring(string s, int k) {
        int n = s.length();
        return getlongest(0,n-1,s,k);
    }
};