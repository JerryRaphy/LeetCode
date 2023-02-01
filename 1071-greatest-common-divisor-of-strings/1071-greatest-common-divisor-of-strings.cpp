class Solution {
public:
    string gcdOfStrings(string a, string b) {
        int n = a.length();
        int m = b.length();
        
        if(n > m) return gcdOfStrings(b,a);
        
        string res,curr;
        
        for(int i=0 ; i<n ; ++i){
            curr.push_back(a[i]);
            int len = i + 1;
            
            int j = 0;
            bool check1 = true;

            while(j < m){
                string temp = b.substr(j,len);
                if(temp != curr){
                    check1 = false;
                    break;
                }
                j += len;
            }

            
            j = 0;
            bool check2 = true;
            
            while(j < n){
                string temp = a.substr(j,len);
                if(temp != curr){
                    check2 = false;
                    break;
                }
                j += len;
            }
            
            if(check1 && check2) res = curr; 
        }
        return res;
    }
};