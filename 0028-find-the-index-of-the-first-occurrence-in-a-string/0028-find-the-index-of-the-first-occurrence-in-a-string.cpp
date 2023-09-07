class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.size();
        
        if(m > n) return -1;
        
        vector<int> prefix(m,0);
        int i = 1;
        int len = 0;
        
        while(i < m){
            if(needle[i] == needle[len]){
                prefix[i] = len + 1;
                len += 1;
                i += 1;
            }
            else{
                if(len != 0){
                    len = prefix[len - 1];
                }
                else{
                    i += 1;
                }
            }
        }
        
        i = 0;
        int j = 0;
    
        while(i < n){
            if(haystack[i] == needle[j]){
                i += 1;
                j += 1;
            }   
            else{
                if(j != 0){
                    j = prefix[j - 1];
                }
                else i += 1;
            }
            
            if(j == m) return i - m;
        }
        
        return -1;
        
    }
};