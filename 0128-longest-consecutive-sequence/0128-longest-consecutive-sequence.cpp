class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        set<int> st;
        
        for(int i=0 ; i<n ; ++i){
            st.insert(nums[i]);
        }
        
        int len = 0;
        
        for(int i=0 ; i<n ; ++i){
            
            if(st.find(nums[i] - 1) == st.end()){
                int curr_streak = 1;
                int number = nums[i] + 1;
                
                while(st.find(number) != st.end()){
                    curr_streak += 1;
                    number += 1;
                }
                
                len = max(len,curr_streak);
            }
        }
        
        return len;
    }
};