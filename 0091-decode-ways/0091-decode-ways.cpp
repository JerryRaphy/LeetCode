class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        vector<int> dp(n,0);
        if(s[0] == '0') return 0;
        
        dp[0] = 1;
        for(int i=1 ; i<n ; ++i){
            string temp;
            temp.push_back(s[i-1]);
            temp.push_back(s[i]);
            bool entered = false;
            
            if(stoi(temp) >= 10 && stoi(temp) <= 26){
                entered = true;
                if(i != 1) dp[i] += dp[i-2]; 
                else dp[i] += 1;
            }
            
            if(s[i] == '0' && !entered) return 0;
            else if(s[i] != '0') dp[i] += dp[i-1];
            
            
        }
        return dp[n-1];
    }
};