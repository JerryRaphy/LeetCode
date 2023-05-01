class Solution {
public:
    int nthUglyNumber(int n) {
    
        vector<int> v(1691,0);
        v[0] = 1;
        
        int ugly = 0;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        
        for(int i=1 ; i<1690 ; ++i){
            ugly = min(v[p2] * 2,min(v[p3] * 3,v[p5] * 5));
            v[i] = ugly;
            
            if(v[p2] * 2 == ugly) p2 += 1;
            if(v[p3] * 3 == ugly) p3 += 1;
            if(v[p5] * 5 == ugly) p5 += 1;
        }
        
        return v[n - 1];
    }
};