class Solution {
public:
    string convert(string s, int numRows) {
        
        int n = s.length();
        vector<string> v(numRows);
        
        if(numRows == 1) return s;
        
        bool toptobottom = true;
        int row = 0;
        
        for(int i=0 ; i<n ; ++i){
            if(row == numRows - 1){
                v[row].push_back(s[i]);
                row -= 1;
                toptobottom = false;
            }
            else if(row == 0){
                v[row].push_back(s[i]);
                row += 1;
                toptobottom = true;
                
            }
            else if(toptobottom){
                 v[row].push_back(s[i]);
                 row += 1;
            }
            else if(!toptobottom){
                 v[row].push_back(s[i]);
                 row -= 1;
            }
        }
    
    
        string res;
        for(int i=0 ; i<numRows ; ++i) res += v[i];
        return res;
    
    }
};