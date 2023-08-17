class Solution {
public:
    
    bool static comp(string A, string B){
        string f = A + B;
        string g = B + A;
        return f > g;
    }
    
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        string res;
        
        vector<string> v;
        for(int i=0 ; i<n ; ++i){
            v.push_back(to_string(nums[i]));
        }
        
        sort(v.begin(),v.end(),comp);
        for(auto it : v) res += it;
        
        if(res[0] == '0') return "0";
        return res;
    }
};