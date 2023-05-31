class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        int flips = 0;
        long long ans = 0;
        
        for(int i=1 ; i<n ; ++i){
            if(flips % 2 != 0) {
                if(s[i] == '0') s[i] = '1';
                else s[i] = '0';
            }
            if(s[i] != s[i-1]){
                int prefix = i;
                int suffix = n - i;
                if(prefix <= suffix) ans += prefix;
                else{
                    flips += 1;
                    ans += suffix;
                    s[i] = s[i-1];
                }
            }
        }
        
        return ans;
    }
};