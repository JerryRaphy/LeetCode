class Solution {
public:
    bool winnerOfGame(string colors) {
            
        int n = colors.length();
        
        int cnt_A = 0;
        int cnt_B = 0;
        
        int curr_cnt = 1;
        for(int i=1 ; i<n ; ++i){
            if(colors[i] == colors[i - 1]){
                curr_cnt += 1;
            }
            else{
                if(colors[i - 1] == 'A') cnt_A += max(0,curr_cnt - 2);
                else cnt_B += max(0,curr_cnt - 2);
                curr_cnt = 1;
            }
        }
    
        if(colors[n - 1] == 'A') cnt_A += max(0,curr_cnt - 2);
        else cnt_B += max(0,curr_cnt - 2);  
    
        return cnt_A > cnt_B ? true : false;
        
    }
};