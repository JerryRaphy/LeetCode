//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long getnumberofways(int dice, long long sum, int N, int M, int X,
    vector<vector<long long>> &dp){
        
        // base cases
        if(dice == N + 1 && sum == X) return 1;
        
        if(dice > N || sum > X) return 0;
        
        long long ways = 0;
        
        if(dp[dice][sum] != -1) return dp[dice][sum];
        
        for(int i=1 ; i<=M ; ++i){
            
            // take one value each time
            ways += getnumberofways(dice+1,sum + i,N,M,X,dp);
            
        }
        
        return dp[dice][sum] = ways;
        
    }
  
    long long noOfWays(int M , int N , int X) {
        
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return getnumberofways(1,0,N,M,X,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends