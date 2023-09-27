class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        
        int n = heights.size();
        
        
        vector<long long> nse(n,n);
        stack<int> st;
        
        for(int i=n-1 ; i>=0 ; --i){
            while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        
        vector<long long> right(n);
        for(int i=n-1 ; i>=0 ; --i){
            if(nse[i] == n) right[i] = (n - i) * 1LL * heights[i];
            else{
                int between = nse[i] - i;
                right[i] = (between * 1LL * heights[i]) + right[nse[i]];
            }
        }
        
        // for(int i=0 ; i<n ; ++i) cout<<right[i]<<" ";
        
        while(!st.empty()) st.pop();
        vector<int> pse(n,-1);
        
        for(int i=0 ; i<n ; ++i){
            while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        
        // for(int i=0 ; i<n ; ++i) cout<<pse[i]<<" ";
        // cout<<endl;
        
        vector<long long> left(n);
        for(int i=0 ; i<n ; ++i){
            if(pse[i] == -1) left[i] = (i + 1) * 1LL *  heights[i];
            else{
                int between = i - pse[i];
                left[i] = (between * 1LL *  heights[i]) + left[pse[i]];
            }
        }
     
        long long res = 0;
        for(int i=0 ; i<n ; ++i){
            if(i == 0) res = right[i];
            else if(i == n - 1) res = max(res,left[i]);
            else res = max(res,left[i] + right[i+1]);
        }

        return res;
        
    }
};