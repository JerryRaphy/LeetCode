class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.length();
        int left_mn = 0;
        int left_mx = 0;
        
        for(int i=0 ; i<n ; ++i){
            if(s[i] == '('){
                left_mn += 1;
                left_mx += 1;
            }
            else if(s[i] == ')'){
                left_mn -= 1;
                left_mx -= 1;
            }
            else{
                left_mn -= 1;
                left_mx += 1;
            }
            
            if(left_mx < 0) return false;
            if(left_mn < 0) left_mn = 0;
        }
        
        return left_mn == 0;
    }
};