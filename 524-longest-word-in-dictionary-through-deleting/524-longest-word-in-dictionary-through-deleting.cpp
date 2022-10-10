class Solution {
public:
    
    bool checker(string &A, string &B){
        int n = A.length();
        for(int i=0 ; i<n ; ++i){
            if(A[i] < B[i]) return true;
            else if(B[i] < A[i]) return false;
        }
        return true;
    }
    
    string findLongestWord(string s, vector<string>& dict) {
        int n = s.length();
        int m = dict.size();
        string ans;
        int len = 0;
        
        
        for(int i=0 ; i<m ; ++i){
            string curr = dict[i];
            int sz = curr.length();
            
            int j = 0; // iterates over s
            int k = 0; // iterates over curr
            
            while(j < n && k < sz){
                if(s[j] == curr[k]){
                    ++j;
                    ++k;
                }
                else ++j;
            }
            
            if(k == sz){
                if(sz > len){
                    len = sz;
                    ans = curr;
                }
                else if(sz == len){
                    if(checker(curr,ans)) ans = curr;
                }
            }
        }
        return ans;
    }
};