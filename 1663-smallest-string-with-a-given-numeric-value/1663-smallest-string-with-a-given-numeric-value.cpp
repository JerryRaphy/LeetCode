class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string res;
        for(int i=0 ; i<n ; ++i) res.push_back('a');
        int sum = n;
        
        for(int i=n-1 ; i>=0 ; --i){
            if(sum == k) break;
            int required_diff = min(26,k - (sum - 1));
            res[i] = char(96 + required_diff);
            sum = (sum - 1) + required_diff;
        }
        
        return res;
    }
};