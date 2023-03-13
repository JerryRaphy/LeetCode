class Solution {
public:

    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        vector<string> res;
        map<string,int> freq;       
        
        for(auto word : words) freq[word]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>> pq;
        
        for(auto it : freq){    
            pq.push({-it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};