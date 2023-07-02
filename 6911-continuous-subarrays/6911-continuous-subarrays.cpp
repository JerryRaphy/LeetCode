class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        long long res = 0;
        
        multiset<int> st;
        int l = 0;
        int r = 0;
        
        while(r < n){
            st.insert(nums[r]);
            
            while(st.size() > 1 && *st.rbegin() - *st.begin() > 2){
                st.erase(st.find(nums[l]));
                l += 1;
            }
            
            res += r - l + 1;
            r += 1;
        }
        
        return res;
    }
};