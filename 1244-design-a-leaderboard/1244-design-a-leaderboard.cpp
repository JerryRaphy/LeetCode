class Leaderboard {
public:
    
    map<int,int> mp;
    
    Leaderboard() {
       mp.clear();
    }
    
    void addScore(int playerId, int score) {
        if(mp.find(playerId) != mp.end()) mp[playerId] += score;
        else mp[playerId] = score;
    }
    
    int top(int K) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : mp){
            pq.push(it.second);
            if(pq.size() > K) pq.pop();
        }
        
        int score = 0;
        while(!pq.empty()){
            score += pq.top();
            pq.pop();
        }
        
        return score;
    }
    
    void reset(int playerId) {
        mp.erase(playerId);   
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */