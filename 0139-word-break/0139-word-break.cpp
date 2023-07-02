class Solution {
public:
    bool wordBreak(string A, vector<string>& B) {
        int n = A.length();
        vector<bool> dp(n+1,false);
        dp[n] = true;

        set<string> st;
        for(auto word : B) st.insert(word);

        for(int i=n-1 ; i>=0 ; --i){
            for(int j=i ; j<n ; ++j){
                string curr = A.substr(i,j-i+1);
                int len = j - i + 1;
                if(st.count(curr) && dp[i + len]) dp[i] = true;
            }
        }

        return dp[0];
    }
};