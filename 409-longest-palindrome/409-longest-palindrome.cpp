class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        
        int n = s.length();
        int ans = 0;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            int f = it->second;
            ans += (f/2) * 2;
        }
        if(ans < n) ++ans;
        return ans;
    }
};