class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        int mx_candies = *max_element(candies.begin(),candies.end());
        vector<bool> res(n,false);
        
        for(int i=0 ; i<n ; ++i){
            if(candies[i] + extraCandies >= mx_candies) res[i] = true;
        }
        
        return res;
    }
};