class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        int total = 0;
        
        
        int l = 0;
        int r = 0;
        
        vector<int> curr(n,0);
        for(int i=0 ; i<n ; ++i){
            if(i == 0) continue;
            else if(fruits[i] == fruits[i-1]) curr[i] = curr[i-1] + 1;
        }
        
        set<int> st;
        
        while(r < n){
            if(st.size() < 2) st.insert(fruits[r]);
            else if(st.find(fruits[r]) != st.end()) r += 0;
            else{
              total = max(total,r - l);
              int new_l_pos = (r - 1) - curr[r - 1];
              st.erase(fruits[new_l_pos - 1]);
              st.insert(fruits[r]);
              l = new_l_pos;  
            }
            r += 1;
        }
        
        total = max(total,r - l);
        return total;
    }
};