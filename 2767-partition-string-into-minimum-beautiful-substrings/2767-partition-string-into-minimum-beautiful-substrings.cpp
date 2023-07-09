class Solution {
public:
    
    set<int> st;
    
    bool isbeautiful(string curr){
        
        long long int f = 0;
        int n = curr.length();
        int pw = 0;
        
        for(int i=n-1 ; i>=0 ; --i){
            if(curr[i] == '1'){
                f += pow(2,pw);
            }
            pw += 1;
        }
        
        if(st.count(f)) return true;
        return false;        
        
    }
    
    int solve(int idx, int n, string s){
        
        if(idx == n) return 0;
        if(s[idx] == '0') return 100;
        
        string curr;
        int parts = 100;
        
        for(int i=idx ; i<n ; ++i){
            curr.push_back(s[i]);
            if(isbeautiful(curr)){
                parts = min(parts,solve(i+1,n,s));
            }
        }
        
        return parts + 1;
    }
    
    
    int minimumBeautifulSubstrings(string s) {
        
        int n = s.length();
        st.insert(1);
        st.insert(5);
        st.insert(25);
        st.insert(125);
        st.insert(625);
        st.insert(3125);
        st.insert(15625);
        
        int res = solve(0,n,s);
        if(res >= 100) return -1;
        return res;
    }
};