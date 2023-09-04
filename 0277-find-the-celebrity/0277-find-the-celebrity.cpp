/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        
        int res = -1;
        vector<bool> isceleb(n,true);
        
        for(int i=0 ; i<n ; ++i){
            if(!isceleb[i]) continue;
            for(int j=0 ; j<n ; ++j){
                if(i != j){
                    if(knows(i,j)){
                        isceleb[i] = false;
                    }
                    else isceleb[j]  = false;
                    
                    if(!knows(j,i))
                         isceleb[i] = false;
                    else isceleb[j] = false;
                }
            }
        }
        
        for(int i=0 ; i<n ; ++i) {
            if(isceleb[i]) return i;
        }
        
        return -1;
        
    }
};