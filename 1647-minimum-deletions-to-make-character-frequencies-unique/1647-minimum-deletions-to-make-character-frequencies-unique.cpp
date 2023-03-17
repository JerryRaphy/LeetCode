class Solution {
public:
    int minDeletions(string s) {
        
        int n = s.length();
        vector<int> freq(n+1,0);
        
        map<char,int> mp;
        for(int i=0 ; i<n ; ++i) mp[s[i]]++;
        
        for(auto it : mp) freq[it.second] += 1;
        
        int res = 0;
        for(int i=n ; i>0 ; --i){
            if(freq[i] == 0 || freq[i] == 1) continue;
            else{
                freq[i - 1] += freq[i] - 1;
                res += freq[i] - 1;
            }
        }
        
        return res;
        
    }
};