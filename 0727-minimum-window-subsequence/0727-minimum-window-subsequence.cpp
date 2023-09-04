class Solution {
public:
    string minWindow(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        if(m > n) return "";
        
        vector<vector<int>> v(26);
        for(int i=0 ; i<n ; ++i){
            int ch = s1[i] - 'a';
            v[ch].push_back(i);
        }
        
        int l = 0;
        int r = n;
        int max_len = n + 1;     
        
        int start = s2[0] - 'a';
        
        for(int i=0 ; i<v[start].size() ; ++i){
            int prev = v[start][i];
            int j = 1;
            
            while(j < m){
                int ch = s2[j] - 'a';
                int sz = v[ch].size();
                
                int next_prev = upper_bound(v[ch].begin(), v[ch].end(), prev) - v[ch].begin();
              
                if(next_prev == sz) break;
                else prev = v[ch][next_prev];
                
                j += 1;
            }
            
            if(j == m){
                if(prev - v[start][i] < max_len){
                    max_len = prev - v[start][i];
                    l = v[start][i];
                    r = prev;
                }
            }
        }
        
        if(max_len == n + 1) return ""; 
        return s1.substr(l,r-l+1);
    }
};