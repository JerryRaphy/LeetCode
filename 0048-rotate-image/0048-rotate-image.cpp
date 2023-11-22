class Solution {
public:
    void rotate(vector<vector<int>>& A) {
          int n = A.size();

        // transpose the matrix make rows into cols and vice versa
        for(int i=0 ; i<n ; ++i){
            for(int j=i ; j<n ; ++j){
                int temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
        }

        int l = 0;
        int r = n - 1;

        while(l < r){
            for(int i=0 ; i<n ; ++i){
                int temp = A[i][l];
                A[i][l] = A[i][r];
                A[i][r] = temp;
            }
            l += 1;
            r -= 1;
        }    

        return;   
    }
};