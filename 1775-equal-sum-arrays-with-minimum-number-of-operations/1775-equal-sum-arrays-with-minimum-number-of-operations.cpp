class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
         int l1 = nums1.size(); // l1 ~ 6l1
        int l2 = nums2.size(); // l2 ~ 6l2

        if(6*l1 < l2 || 6*l2 < l1) {
            return -1;
        }
        
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1 > sum2) return minOperations(nums2, nums1);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>());
     
        int ans = 0, ptr1 = 0, ptr2 = 0; 
        int diff = sum2 - sum1;

        while(diff > 0) {
            if(ptr2 == l2 || ptr1 < l1 && (6 - nums1[ptr1]) >= (nums2[ptr2] - 1)) {
                diff -= (6 - nums1[ptr1]);
                ans++;
                ptr1++;
            }
            else {
                diff -= (nums2[ptr2] - 1);
                ans++;
                ptr2++;
            }
        }
        return ans;
    }
};