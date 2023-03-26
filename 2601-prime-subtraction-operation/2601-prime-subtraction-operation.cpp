class Solution {
public:
    
    bool primeSubOperation(vector<int>& nums) {
        
        int n = nums.size();
        int max = *max_element(nums.begin(),nums.end());
    
        
        vector<bool> prime(max + 1,true);
        prime[0] = false;
        prime[1] = false;
        
        for (int p = 2; p * p <= max; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= max; i += p)
                    prime[i] = false;
            }
        }
        
        vector<int> v;
        for(int i=0 ; i<=max ; ++i){
            if(prime[i]) v.push_back(i);
        }
    
        int l = 0;
        int r = v.size() - 1;
        int res = -1;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(v[mid] < nums[0]){
                res = v[mid];
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        if(res != -1) nums[0] -= res;
        
        for(int i=1 ; i<n ; ++i){
            int l = 0;
            int r = v.size() - 1;
            int res = -1;
            
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(nums[i] - v[mid] > nums[i - 1]){ 
                    res = v[mid];
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            
            if(res != -1) nums[i] -= res;
            else if(res == -1){
                if(nums[i] > nums[i - 1]) continue;
                else return false;
            }
        }
        
        return true;
    }
};