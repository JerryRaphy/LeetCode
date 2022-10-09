class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minsuffix(n);
        minsuffix[n-1] = s[n-1];
        
        for(int i=n-2 ; i>=0 ; --i) minsuffix[i] = min(minsuffix[i+1],s[i]);
        
        int i = 0;
        string t;
        string res;
        
        while(i < n){
            if(t.empty()){
                t.push_back(s[i]);
                ++i;
                continue;
            }
            
            if(t.back() > minsuffix[i]){
                char min_req = minsuffix[i];
                while(s[i] != min_req){
                    t.push_back(s[i]);
                    ++i;
                }
                t.push_back(s[i]);
                ++i;
            }
            
            res.push_back(t.back());
            t.pop_back();
        }
        
        
        while(!t.empty()){
            res.push_back(t.back());
            t.pop_back();
        }
        
        return res;
    }
};