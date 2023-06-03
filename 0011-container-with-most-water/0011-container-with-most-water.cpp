class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxarea = 0;
        int n = height.size();
        int l = 0;
        int r = n - 1;
        
        while(l <= r){
            mxarea = max(mxarea,min(height[l],height[r]) * (r - l));
            if(height[l] <= height[r]) l += 1;
            else r -= 1;
        }
        
        return mxarea;
    }
};