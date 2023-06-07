class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> maxheightleft(n,0);
        vector<int> maxheightright(n,0);
        int res = 0;
        
    
        for(int i=1; i<n ; ++i){
            maxheightleft[i]  = max(maxheightleft[i-1],height[i-1]);
        }
        
        for(int i=n-2; i>=0 ; --i){
            maxheightright[i] = max(maxheightright[i+1],height[i+1]);
        }
        
        
        for(int i=0 ; i<n ; ++i){
            int minh = min(maxheightright[i],maxheightleft[i]);
            if(minh >= height[i]) res += minh - height[i];
        }
        
        
        return res;
    }
};