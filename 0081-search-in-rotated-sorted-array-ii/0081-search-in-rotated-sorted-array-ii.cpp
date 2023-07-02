class Solution {
public:
    bool search(vector<int>& A, int B) {
        int n = A.size();
        int l = 0;
        int r = n - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(A[mid] == B) return true;

            if(A[l] == A[mid] && A[mid] == A[r]){
                l += 1;
                r -= 1;
                continue;
            }
            
            if(A[l] <= A[mid]){
                if(A[l] <= B && B <= A[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else{
                if(A[mid] <= B && B <= A[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        
        return false;
    }
};