#define ll long long

class Solution {
public:
    
    bool func(vector<int> &ranks, int cars, ll mid, int n){
        for(int i=0 ; i<n ; ++i){
           ll temp = mid / ranks[i];
           temp = sqrt(temp);
           cars -= temp;
           if(cars <= 0) return true;
        } 
        return false;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        
        int n = ranks.size();
           
        ll l = 0;
        ll r = 1e14;
        ll res = r;
        
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(func(ranks,cars,mid,n)) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return res;
    }
};