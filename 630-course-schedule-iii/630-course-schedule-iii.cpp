class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(),courses.end(),comp);
        int start = 1;
        
        priority_queue<int> pq;
        for(int i=0 ; i<n ; ++i){
            int curr = start + courses[i][0];
            if(curr-1 <= courses[i][1]){
                pq.push(courses[i][0]);
                start = curr;
            }
            else{
                if(pq.empty() || pq.top() < courses[i][0]) continue;
                start -= pq.top();
                pq.pop();
                start += courses[i][0];
                pq.push(courses[i][0]);
            }
        }
        
        return pq.size();
    }
};