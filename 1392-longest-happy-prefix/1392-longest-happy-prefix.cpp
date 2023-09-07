class Solution {
public:
    string longestPrefix(string a) {
        
        int n = a.length();
        string res;
        vector<int> prefix(n,0);
        int i = 1;
        int len = 0;
        
        
        while(i < n){
            if(a[i] == a[len]){
                prefix[i] = len + 1;
                len += 1;
                i += 1;
            }
            else{
                if(len != 0) len = prefix[len - 1];
                else i += 1;
            }
        }
        
        return a.substr(0,prefix[n-1]);          
    }
};