const int mod = 1e9 + 7;
#define ll long long int

class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        
        int n = v.size();
        vector<ll> prevsmallerelement(n);
        vector<ll> nextsmallerelement(n);
        
        stack<int> st;
        
        for(int i=0 ; i<n ; ++i){
            while(!st.empty() && v[st.top()] >= v[i]) st.pop();
            if(st.empty()) prevsmallerelement[i] = i;
            else prevsmallerelement[i] = i - st.top() - 1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1 ; i>=0 ; --i){
            while(!st.empty() && v[st.top()] > v[i]) st.pop();
            if(st.empty()) nextsmallerelement[i] = n - i - 1;
            else nextsmallerelement[i] = st.top() - i - 1;
            st.push(i);   
        }
        
        /*for(int i=0 ; i<n ; ++i) cout<<prevsmallerelement[i]<<" ";
        cout<<endl;
        for(int i=0 ; i<n ; ++i) cout<<nextsmallerelement[i]<<" ";
        cout<<endl;*/
    
        long long int res = 0;
        for(int i=0 ; i<n ; ++i){
            res += (prevsmallerelement[i] + 1) * (nextsmallerelement[i] + 1) * v[i];
            res %= mod;
        }        
    
        return int(res);   
    }
};