class Solution {
public:
    
    vector<int> v;
    
    bool solve(string A, string B){
        
        int n = A.length();
        int m = B.length();
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(v[A[i] - 'a'] > v[B[j] - 'a']) return false;
            else if(v[A[i] - 'a'] < v[B[j] - 'a']) return true;
            
            i += 1;
            j += 1;
        }
        
        if(j == m && i < n) return false;
        return true;    
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
    
        v.resize(26,0);
        
        for(int i=0 ; i<26 ; ++i){
            v[order[i] - 'a'] = i;
        }
                
        int n = words.size();
        for(int i=0 ; i<n-1 ; ++i){
            string A = words[i];
            for(int j=i+1 ; j<n ; ++j){
                string B = words[j];
                if(!solve(A,B)) return false;
            }
        }
        
        return true;
    }
};