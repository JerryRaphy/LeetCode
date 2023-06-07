class Solution {
public:
    int largestVariance(string s) {
        
        int n = s.length();
        int globalmax = 0;
        
        vector<int> freq(26,0);
        for(auto ch : s) freq[ch - 'a'] += 1;
        
        for(int i=0 ; i<26 ; ++i){
            for(int j=0 ; j<26 ; ++j){
                
                if(i == j || freq[i] == 0 || freq[j] == 0) continue;
                char major = char(i + 97);
                char minor = char(j + 97);
                
                int cnt_major = 0;
                int cnt_minor = 0;
                int rem_minor = freq[j];
                
                for(auto ch : s){
                    
                    if(ch == major) cnt_major += 1;
                    else if(ch == minor){
                        cnt_minor += 1;
                        rem_minor -= 1;
                    }
                    
                    if(cnt_minor > 0) globalmax = max(globalmax,cnt_major - cnt_minor);
                    if(cnt_minor > cnt_major){
                        if(rem_minor > 0){
                            cnt_major = 0;
                            cnt_minor = 0;
                        }
                    }
                }
            }
        }
        
        return globalmax;
    }
};