class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        int cnt = 0;
        
        int i = 1;
        int prev = 0;
        int curr_cnt = 1;
        
        
        while(i < n){
            if(chars[i] == chars[i-1]){
                curr_cnt += 1;
            }
            else{
                chars[prev] = chars[i - 1];
                prev += 1;
                cnt += 1;
                
                if(curr_cnt != 1){
                    
                    int f = curr_cnt;
                    int digits = 0;
                    while(f){
                        digits += 1;
                        f /= 10;
                    }
                    
                    int next = prev + digits - 1;
                    
                    while(curr_cnt){
                        int num = curr_cnt % 10;
                        chars[next] = char(48 + num);
                        next -= 1;
                        cnt += 1;
                        curr_cnt /= 10;
                    }
                    
                    prev += digits;
                }
                curr_cnt = 1;
            }
            i += 1;
        }
        
        chars[prev] = chars[i - 1];
        prev += 1;
        cnt += 1;

        if(curr_cnt != 1){

            int f = curr_cnt;
            int digits = 0;
            while(f){
                digits += 1;
                f /= 10;
            }

            int next = prev + digits - 1;

            while(curr_cnt){
                int num = curr_cnt % 10;
                chars[next] = char(48 + num);
                next -= 1;
                cnt += 1;
                curr_cnt /= 10;
            }

            prev += digits;
        }
        curr_cnt = 1;
       
        
        return cnt;
    }
};