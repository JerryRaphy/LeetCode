#define ll long long int

class Solution {
public:
    string fractionToDecimal(int num, int dem) {
        
        ll A = num;
        ll B = dem;
        
        
        // if numerator is 0
        if(A == 0) return  "0";

        string res;

        // check the sign now
        int sign = (A < 0) ^ (B < 0) ? -1 : 1;
        if(sign == -1) res += '-';

        
        if(A < 0) A *= -1;
        if(B < 0) B *= -1;
        
        

        ll initial = A / B;
        res += to_string(initial);
        
        
        // if it is completely divisible, then we return now
        if(A % B == 0){   
            return res;
        }

        // else we add decimal point
        res += '.';

        ll rem = A % B;
        map<ll,ll> mp;
        int idx = -1;
        bool repeating = false;


        while(rem > 0){

            if(mp.count(rem)){
                idx = mp[rem];
                repeating = true;
                break;
            }
            else{
                mp[rem] = res.size();
            }

            rem = rem * 10;
            ll temp = rem / B;
            res += to_string(temp);
            rem = rem % B;

        }

        if(repeating){
            res += ')';
            res.insert(idx,"(");
        }

        return res;
    }
};