class Solution {
public:
    
    
    string lexosmallest(string a, string b){
        if(a.length() < b.length() || (a.length() == b.length() && a < b)) return a;
        return b;
    }
    
    string concatenate(string a, string b){
            
            string res = a;
            string word = b;
            
            int word_pointer = 0;
            int res_pointer = 0;
            int n = res.length();
            
            bool fit = false;
            
            while(res_pointer < n){
                
                int curr = res_pointer;
                while(curr < n && word_pointer < word.length() && res[curr] == word[word_pointer]){
                    curr += 1;
                    word_pointer += 1;
                }
                
                // if the current word already fits in
                if(word_pointer == word.length()){
                    fit = true;
                    break;
                }
                
                // some part of it fits and we append whatever is remaining
                if(curr == n){
                    fit = true;
                    res += word.substr(word_pointer);
                    break;
                }
                    
                res_pointer += 1;
                word_pointer = 0;
            }
            
            // no part of it fits just add the entire word as is
            if(!fit) res += word;
            
            return res;
    }
    
    string getmin(string a, string b, string c){
        string w1 = concatenate(a,b);
        string w2 = concatenate(b,a);
        
     
        string w3 = concatenate(w1,c);
        string w4 = concatenate(w2,c);
        
        
        return lexosmallest(w3,w4);
    }
    
    string minimumString(string a, string b, string c) {
        
        string p = getmin(a,b,c);
        string q = getmin(b,c,a);
        string r = getmin(c,a,b);
        
        return lexosmallest(p,lexosmallest(q,r));
    }
};