class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        int type_1 = -1;
        int type_2 = -1;
        int pos = 0;
        
        vector<int> lastencountered(n);
        lastencountered[0] = 0;
        
        for(int i=1 ; i<n ; ++i){
            if(fruits[i] == fruits[i-1]) lastencountered[i] = lastencountered[i-1];
            else lastencountered[i] = i;
        }
        int i = 0;
        int len = 0;
        
        while(i < n){
            
            if(fruits[i] == type_1 || fruits[i] == type_2) {
                ++i;
                continue;
            }
            
            if(type_1 == -1) type_1 = fruits[i];
            else if(type_2 == -1) type_2 = fruits[i];
            else if(fruits[i] != type_1 && fruits[i] != type_2){
                len = max(len,i-pos);
                pos = lastencountered[i-1];
                type_1 = fruits[i-1];
                type_2 = fruits[i];
            }
            ++i;
        }
       
        len = max(len,i - pos);
        return len; 
    }
};