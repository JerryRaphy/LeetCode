class Solution {
public:
    string rearrangeString(string s, int k) {
        
        int n = s.length();
        string res;
        vector<int> freq(26,0);
        
        for(int i=0 ; i<n ; ++i){
            freq[s[i] - 'a'] += 1;
        }
        
        queue<pair<int,char>> q;
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        
          
        for(int i=0 ; i<26 ; ++i) {
            if(freq[i]) pq.push({freq[i],char(i+97)});
        }
        
        while(!pq.empty()){
            
            int  f = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            
            res.push_back(c);
            q.push({f-1,c});
            
            if(q.size() >= k){
                auto it = q.front();
                q.pop();
                
                if(it.first > 0) pq.push(it);
            }
        }
        
        return res.size() == n ? res : "";
    
    }
};