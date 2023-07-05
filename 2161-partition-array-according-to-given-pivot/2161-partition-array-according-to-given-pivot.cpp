class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        vector<int> res;
        
        int equal = 0;
        vector<int> lesser;
        vector<int> greater;
        
        for(auto num : nums){
            if(num < pivot) lesser.push_back(num);
            else if(num > pivot) greater.push_back(num);
            else equal += 1;
        }
        
        for(auto l : lesser) res.push_back(l);
        while(equal--) res.push_back(pivot);
        for(auto r : greater) res.push_back(r);
        
        return res;
        
    }
};