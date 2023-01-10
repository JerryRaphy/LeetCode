class Solution {
public:
    
    bool static comp(vector<int> A, vector<int> B){
        if(A[1] == B[1]) return A[1] < B[1];
        return A[1] < B[1];
    }

    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        int len = 1;
        int tail = pairs[0][1];
        
        for(int i=1 ; i<n ; ++i){
            if(pairs[i][0] > tail){
                tail = pairs[i][1];
                len += 1;
            }
        }
       
        return len;
    }
};