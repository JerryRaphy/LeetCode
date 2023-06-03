class Solution {
public:
    bool isRegex(int i , int j , string A , string B , int n , int m){
        if(i < 0 && j < 0) return true;
        if(j < 0) return false; 

        bool match = false;
        if(B[j] == '*') return isRegex(i,j-1,A,B,n,m);
        if(i>=0 && (A[i] == B[j] || B[j] == '.')) match = true;
        if(j+1<m && B[j+1] == '*'){
            return (isRegex(i,j-1,A,B,n,m) || (match && isRegex(i-1,j,A,B,n,m)));
        }

        if(match) return isRegex(i-1,j-1,A,B,n,m);
        return false;
        
    }

    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return isRegex(n-1,m-1,s,p,n,m);
    }
};