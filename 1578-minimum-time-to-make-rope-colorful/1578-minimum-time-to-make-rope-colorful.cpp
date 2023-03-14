class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        
        int n = colors.size();
        int cost = 0;
        
        for(int i=0 ; i<n-1 ; ++i){
            if(colors[i] == colors[i+1]){
                if(time[i] < time[i+1]){
                    cost += time[i];
                }   
                else{
                    cost += time[i+1];
                    time[i+1] = time[i];
                }
            }
        }
        
        return cost;

    }
};