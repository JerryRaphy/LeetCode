class Solution {
public:
    void reverseWords(vector<char>& s) {
        
        int n = s.size();
        int r = 0;
        int l = 0;
        
        while(r < n){
            while(r < n && s[r] >= 'a' && s[r] <= 'z') r += 1;
            reverse(s.begin()+l,s.begin()+r);
            
            r += 1;
            l = r;
        }
        
        reverse(s.begin(),s.end());
        return;
    }
};