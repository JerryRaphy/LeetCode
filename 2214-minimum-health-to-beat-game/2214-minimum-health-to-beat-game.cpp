class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        int n = damage.size();
        sort(damage.begin(),damage.end());
        
        long long health = 0;
        for(int i=0 ; i<n-1 ; ++i) health += damage[i];
        
        health += max(0,damage[n - 1] - armor);
        return health + 1;
    }
};