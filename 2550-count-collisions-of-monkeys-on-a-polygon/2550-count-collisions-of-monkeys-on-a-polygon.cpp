const int mod = 1e9 + 7;
#define ll long long int


class Solution {
public:
    
    ll binpow(ll a, ll b) {
        if (b == 0)
            return 1;
        ll res = binpow(a, b / 2) % mod;
        if (b % 2)
            return (res * res * a) % mod;
        else
            return (res * res) % mod;
    }
    
    int monkeyMove(int n) {
        return int((binpow(2,n) - 2 + mod) % mod);
    }
};