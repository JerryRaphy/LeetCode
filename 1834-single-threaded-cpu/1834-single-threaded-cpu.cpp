class Solution {
public:
    

    class comp {
        public:
        bool operator()(pair<int,int> A, pair<int,int> B)
        {
            if(A.first == B.first) return A.second > B.second;
            return A.first > B.first;
        }
    };
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        vector<int> res;
        
        vector<vector<int>> v;        
        for(int i=0 ; i<n ; ++i) v.push_back({tasks[i][0],tasks[i][1],i});
    
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        
        
        long long curr_time = 0;
        int i = 0;
        
        
        while(i < n || !pq.empty()){
            
            // then there are no available tasks so just update current time to the current index start time and check if the current time condition as well
            if(pq.empty() && curr_time < v[i][0]){
                curr_time = v[i][0];
            }
    
            while(i < n && v[i][0] <= curr_time){
                pq.push({v[i][1],v[i][2]});
                i += 1;
                
            }
            
            int next_task_index = pq.top().second;
            int next_task_time  = pq.top().first;
            pq.pop();

            
            curr_time += next_task_time;
            res.push_back(next_task_index);
        }
        
        return res;
        
        
    }
};