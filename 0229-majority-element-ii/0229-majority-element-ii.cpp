class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int cnt_1 = 0;
        int cnt_2 = 0;
        
        int candidate_1 =  INT_MIN;
        int candidate_2 =  INT_MIN;
        
        for(int i=0 ; i<n ; ++i){
            if(candidate_1 == nums[i]){
                cnt_1 += 1;
            }   
            else if(candidate_2 == nums[i]){
                cnt_2 += 1;
            }
            else if(cnt_1 == 0){
                candidate_1 = nums[i];
                cnt_1 += 1;
            }
            else if(cnt_2 == 0){
                candidate_2 = nums[i];
                cnt_2 += 1;
            }
            else {
                cnt_1 -= 1;
                cnt_2 -= 1;
            }
        }
        
        cnt_1 = 0;
        cnt_2 = 0;
        
        for(int i=0 ; i<n ; ++i){
            if(nums[i] == candidate_1) cnt_1 += 1;
            else if(nums[i] == candidate_2) cnt_2 += 1;
        }
        
        vector<int> res;
        if(cnt_1 > n / 3) res.push_back(candidate_1);
        if(cnt_2 > n / 3) res.push_back(candidate_2);
        
        return res;
        
    }
};