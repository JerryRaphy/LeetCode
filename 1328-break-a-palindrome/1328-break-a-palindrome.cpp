class Solution {
public:
    string breakPalindrome(string s) {
        
        int n = s.length();
        if(n == 1) return "";
        
        if(n % 2 == 0){
            int cnt_A = 0;
            for(int i=0 ; i<n ; ++i){
                if(s[i] == 'a') cnt_A += 1;
                else {
                    s[i] = 'a';
                    break;
                }
            }
            
            if(cnt_A == n) s[n - 1] = 'b';
        }
        else{
            int cnt_A = 0;
            for(int i=0 ; i<n ; ++i){
                if(s[i] == 'a') cnt_A += 1;
            }
        
            if(cnt_A == n || cnt_A == n - 1) s[n - 1] = 'b'; 
            else{
                for(int i=0 ; i<n ; ++i){
                    if(s[i] != 'a'){
                        s[i] = 'a';
                        break;
                    }
                }
            }
        }
        return s;
    }
};