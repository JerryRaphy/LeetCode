class Solution {
public:
    int minimumOperations(string num) {
        
        int n = num.length();
        int res = n + 1;
        int cnt_zeros = 0;
        
        for(int i=n-1 ; i>=0 ; --i){
            if(num[i] == '0') cnt_zeros += 1;
            for(int j=i+1 ; j<n ; ++j){
                if(num[j] == '0'){
                    if(num[i] == '5' || num[i] == '0'){
                        res = min(res, (j - i) - 1 + (n - j) - 1);
                    }
                }
                else if(num[j] == '5'){
                    if(num[i] == '2' || num[i] == '7'){
                        res = min(res, (j - i) - 1 + (n - j) - 1);
                    }
                }
            }
        }
        
        if(res != n + 1) return res;
        if(cnt_zeros == 1) return n - 1;
        return n;
        
    }
};