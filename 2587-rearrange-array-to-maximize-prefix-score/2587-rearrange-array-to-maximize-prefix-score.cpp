#define ll long long int

class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        
        for(int i=0 ; i<n ; ++i){
            if(nums[i] <= 0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        
        int r = pos.size() - 1;
        int l = neg.size() - 1;
        ll temp = 0;
        int cnt = 0;
        
        while(r >= 0 && l >= 0){
            
            if(temp + neg[l] > 0){
                temp += neg[l];
                l -= 1;
                cnt += 1;
            }
            else{
                temp += pos[r];
                r -= 1;
                if(temp >= 0) cnt += 1;
            }
            
        }
        
        while(l >= 0){
            if(temp + neg[l] > 0){
                temp += neg[l];
                cnt += 1;
            }
            l -= 1;
        }
        
        while(r >= 0){
            if(temp + pos[r] > 0){
                temp += pos[r];
                cnt += 1;
            }
            r -= 1;
        }
        
        return cnt;
    }
};