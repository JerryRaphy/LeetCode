class Solution {
public:
    
    bool static comp(vector<int> &A, vector<int> &B){
        if(A[1] == B[1]) return A[0] < B[0];
        return A[1] < B[1];
    }
    
    int findMinimumTime(vector<vector<int>>& tasks) {
       
        int n = tasks.size();
        sort(tasks.begin(),tasks.end(),comp);
        
        set<int> s;
        int time = 0;
        
        for(int i=0 ; i<n ; ++i){
            int st = tasks[i][0];
            int en = tasks[i][1];
            int du = tasks[i][2];
            
            for(int j=en ; j>=st ; --j){
                if(du == 0) break;
                if(s.find(j) != s.end()) du -= 1;
            }
            
            for(int j=en ; j>=st ; --j){
                if(du == 0) break;
                if(s.find(j) == s.end())  {
                    s.insert(j);
                    du -= 1;
                    time += 1;
                } 
            }
        }
        
        return time;
    }
};