class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.length();
        int cnt_ones = 0;
        int cnt_zero = 0;
        
        for(int i=0 ; i<n ; ++i){
            if(s[i] == '0') cnt_zero++;
            else cnt_ones++;
        }
        
        int curr_ones = 0;
        int curr_zero = 0;
        
        long long cnt = 0;
        
        for(int i=0 ; i<n ; ++i){
            if(s[i] == '1'){
                cnt += (curr_zero * cnt_zero);
                ++curr_ones;
                --cnt_ones;
            }
            else{
                cnt += (curr_ones * cnt_ones);
                ++curr_zero;
                --cnt_zero;
            }
        }
        
        return cnt;
    }
};