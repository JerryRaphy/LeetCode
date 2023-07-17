class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        vector<int> left_dominant(n,-1);
        int mx_count = nums[0];
               
        for(int i=0 ; i<n ; ++i){
            
            mp[nums[i]] += 1;
            int freq = mp[nums[i]];
            
            if(freq * 2 > (i + 1)){
                mx_count = nums[i];
                left_dominant[i] = mx_count;
            }
            else if(mp[mx_count] * 2 > (i + 1)) left_dominant[i] = mx_count;
            
        }
        
        
        
        mp.clear();
        mx_count = nums[n-1];
        vector<int> right_dominant(n,-1);
        
        for(int i=n-1 ; i>=0 ; --i){
            
            mp[nums[i]] += 1;
            int freq = mp[nums[i]];
            
            if(freq * 2 > (n - i)){
                mx_count = nums[i];
                right_dominant[i] = mx_count;
            }
            else if(mp[mx_count] * 2 > (n - i)) right_dominant[i] = mx_count;
            
        }
        
        
        
        for(int i=0 ; i<n-1 ; ++i) {
            if(left_dominant[i] != -1 && right_dominant[i+1] == left_dominant[i]) return i;
        }
        
        return -1;
    }
};