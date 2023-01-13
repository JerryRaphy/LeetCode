class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        stack<char> st;
        
        for(int i=0 ; i<n ; ++i){
            while(!st.empty() && k > 0 && st.top() > nums[i]){
                st.pop();
                k -= 1;
            }
            st.push(nums[i]);
        }
        
        for(int i=0 ; i<k ; ++i){
            st.pop();
        }
        
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        int m = res.length();
        for(int i=m-1 ; i>=0 ; --i){
            if(res[i] != '0') break;
            res.pop_back();
        }
        
        reverse(res.begin(),res.end());    
        if(res.length() == 0) return "0";
        return res;
        
    }
};