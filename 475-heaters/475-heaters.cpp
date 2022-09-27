class Solution {
public:
    
    bool solve(int radius, int n, int m, vector<int> &houses, vector<int> &heaters){
        int i = 0;
        int j = 0;
        while(i < n){
            if(j == m) return false;
            int left_range  = heaters[j] - radius;
            int right_range = heaters[j] + radius;
            
            if(houses[i] < left_range || houses[i] > right_range) ++j;
            else ++i;
        }
        return true;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
         sort(houses.begin(),houses.end());
         sort(heaters.begin(),heaters.end());
        
         int n = houses.size();
         int m = heaters.size();
        
         int low  = 0;
         int high = INT_MAX;
        
         int rad = -1;
        
         while(low <= high){
             int mid = low + (high - low) / 2;
             if(solve(mid,n,m,houses,heaters)){
                 rad = mid;
                 high = mid - 1;
             }
             else low = mid + 1;
         }
         
         return rad;
    }
};