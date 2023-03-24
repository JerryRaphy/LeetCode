class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        int n = s.length();
        if(k == 1){
            string res = s;
            for(int i=1 ; i<n ; ++i){
                string curr = s.substr(i) + s.substr(0,i);
                if(curr < res) res = curr;
            }
            return res;
        }
        else{
            sort(s.begin(),s.end());
            return s;
        }
        return s;
        
    }
};