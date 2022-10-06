class Solution {
public:
    
    static bool comp(vector<int> &A, vector<int> &B){
        if(A[0] == B[0]) return A[1] > B[1];
        return A[0] < B[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) { 
        vector<int> maxenvs;
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        
        for(int i=0 ; i<n ; ++i){
            auto it = lower_bound(maxenvs.begin(),maxenvs.end(),envelopes[i][1]);
            if(it == maxenvs.end()) maxenvs.push_back(envelopes[i][1]);
            else *it = envelopes[i][1];
        }
        
        return maxenvs.size();
    }
};