class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> res;
        int n = words.size();
        
        int i = 0;
        int j = 0;
        
        while(j < n){
            
            string curr;
            
            int curr_len = words[i].length();
            j = i + 1;
            
            while(j < n && ((curr_len + words[j].length() + j - i) <= maxWidth)){
                curr_len += words[j].length();
                j += 1;
            }
            
            // only one word so left justify it
            if(j == i + 1){
                int extra_length = maxWidth - curr_len;
                curr += words[i];
                while(extra_length--) curr.push_back(' ');
                res.push_back(curr);
                i = j;
                continue;
            }
            
            
            // we have reached the last row now
            if(j == n){
                   
               int extra_length = maxWidth - curr_len;
                
                while(i < j - 1){
                    curr += words[i];
                    curr.push_back(' ');
                    if(extra_length) extra_length -= 1;
                    i += 1;
                }
                
                curr += words[i];
                while(extra_length--) curr.push_back(' ');
                res.push_back(curr);
                break;
            }
            
            
            int extra_length = maxWidth - curr_len;
            int spaces_needed = j - i - 1;
            int spaces_length = extra_length / spaces_needed;
            int extra_spaces = extra_length % spaces_needed;
            
            while(i < j){
                curr += words[i];
                
                if(i == j - 1){
                    i += 1;
                    break;
                }
                
                for(int k=0 ; k<spaces_length ; ++k) curr.push_back(' ');
                
                if(extra_spaces){
                    curr.push_back(' ');
                    extra_spaces -= 1;
                }
                
                i += 1;
            }
            
            res.push_back(curr);
        }
        
        return res;
    }
};