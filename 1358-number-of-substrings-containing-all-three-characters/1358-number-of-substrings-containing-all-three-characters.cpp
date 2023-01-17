class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length();
        map<char,int> mp;
        int cnt = 0;
        int r = 0;
        int l = 0;
        
        while(r < n){
            
            mp[s[r]]++;
            while(mp.size() == 3){
                cnt += 1 + (n - r - 1);
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l += 1;
            }
            ++r;
        }
        
        return cnt;
    }
};