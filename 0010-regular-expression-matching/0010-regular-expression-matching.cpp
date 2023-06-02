class Solution {
public:
    
    
       bool isregularexpression(int i, int j, string &A, string &B, int n, int m){
        if(i >= n && j >= m) return true;
        if(j >= m) return false;

        bool match = false;
        if(i < n && (A[i] == B[j] || B[j] == '.')) match = true;

        if(j+1 < m && B[j+1] == '*')
            if(isregularexpression(i,j+2,A,B,n,m) || (match && isregularexpression(i+1,j,A,B,n,m))) return true;
           
        if(match) return isregularexpression(i+1,j+1,A,B,n,m);
        return false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
    
        return isregularexpression(0,0,s,p,n,m);
    }
};