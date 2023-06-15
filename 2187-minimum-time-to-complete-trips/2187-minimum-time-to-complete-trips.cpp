#define ll long long

class Solution {
public:
    
    
    bool ispossible(ll mid, vector<int> &time, int trips){
        
        ll curr = 0;
        int n = time.size();
        
        for(int i=0 ; i<n ; ++i){
           curr += (mid / time[i]);  
        }
        
        if(curr >= trips) return true;
        return false;
    }
    
    long long minimumTime(vector<int>& time, int trips) {
        
        int n = time.size();
        sort(time.begin(),time.end());
        
        ll l = time[0];
        ll r = (1LL * time[n-1]) * trips;
        ll mintime = r;
        
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(ispossible(mid,time,trips)){
                mintime = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return mintime;
    }
};