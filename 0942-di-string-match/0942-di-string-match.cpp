class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        int n = s.length();
        int i = 0;
        int num = 0;
        vector<int> res;
        
        while(i < n){
            
            int j = i;
            while(j < n && s[j] == 'I') j += 1;
            int len = j - i;
            
            while(len--) res.push_back(num++);
            
            i = j;
            while(j < n && s[j] == 'D') j += 1;
            len = j - i;
            
            int f = num + len;
            while(f >= num) res.push_back(f--);
            
            num += len + 1;
            i = j + 1;
            
        }
        
        if(n > 1 && s[n - 2] == 'D' && s[n - 1] == 'I') res.push_back(num);
        return res;
        
        
    }
};