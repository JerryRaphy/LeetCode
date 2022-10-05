class Solution {
public:
   
    //returns true if f > ans 
    bool comp(string ans , string f){
        int n = ans.length();
        for(int i=0 ; i<n ; ++i){
            if(f[i] > ans[i]) return true;
            else if(ans[i] > f[i]) return false;
        }
        return false;
    }
    
    string removeDigit(string number, char digit) {
        int n = number.length();
        string ans;
        for(int i=0 ; i<n ; ++i){
            if(number[i] == digit){
                string f;
                if(i != 0) f = number.substr(0,i);
                if(i != n-1) f += number.substr(i+1,n-i-1);
                if(ans.length() == 0) ans = f;
                else if(comp(ans,f)) ans = f;
            }
        }
        return ans;
    }
};