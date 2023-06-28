class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
         int n = 1e5;
         vector<long long> freq(1e5+1,0);
        
         for(int i=0 ; i<nums1.size() ; ++i) {
             freq[abs(nums1[i] - nums2[i])] += 1;
         }
        
         int operations = k1 + k2;
         for(int i=n ; i>=1 ; --i){
             
             if(freq[i] > operations){
                  freq[i-1] += operations;
                  freq[i] -= operations;
                  operations = 0;
                  break; 
             }
             else{
                 freq[i-1] +=  freq[i];
                 operations -= freq[i];
                 freq[i] = 0;
                 
             }
         }
        
        long long ans = 0;
        for(long long i=0 ; i<=n ; ++i){
            if(freq[i] != 0){
                ans += i * i * freq[i];
            }
        }
        
        return ans;
    }
};