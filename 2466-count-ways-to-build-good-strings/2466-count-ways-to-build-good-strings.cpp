#define ll long long int
const int mod = 1e9 + 7;

class Solution {
public:
    
    vector<ll> dp;
    
    ll solve(int len, int zero, int one, int low, int high){
        ll cnt = 0;

        if(len > high) return 0;
        if(len >= low) cnt += 1;
        
        if(dp[len] != -1) return dp[len];
        cnt = (cnt%mod + solve(len+zero,zero,one,low,high)%mod) % mod;
        cnt = (cnt%mod + solve(len+one,zero,one,low,high)%mod)  % mod;
        
        return dp[len] = cnt % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1,-1);
        return int(solve(0,zero,one,low,high) % mod);
    }
};