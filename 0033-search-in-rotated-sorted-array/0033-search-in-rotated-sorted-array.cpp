class Solution {
public:
    int search(vector<int>& A, int B) {
        
        int n = A.size();
        int l = 0;
        int r = n - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(A[mid] == B) return mid;

            if(A[l] <= A[mid]){
                if(A[l] <= B && B <= A[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else{
                if(A[mid] <= B && B <= A[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        
        return -1;
    }
};