class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int number = start ^ goal;
        int setbits = 0;
        
        while(number){
            number = number & (number - 1);
            setbits += 1;
        }
        
        return setbits;
    }
};