class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       
       int n = heights.size(); 
       stack<int> st;
        
       vector<int> res(n); 
       for(int i=n-1 ; i>=0 ; --i){
           int cnt = 0;
           while(!st.empty() && st.top() < heights[i])  {
              cnt += 1;
              st.pop();
           } 
           if(st.empty()) res[i] = cnt;
           else res[i] = cnt + 1;
           st.push(heights[i]);
       } 
       
       return res; 
    }
};