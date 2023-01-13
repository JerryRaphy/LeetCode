class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n = senate.length();
        
        queue<int> r,d;
        for(int i=0 ; i<n ; ++i){
            if(senate[i] == 'D') d.push(i);
            else r.push(i);
        }
        
        while(!r.empty() && !d.empty()){
            int rt = r.front();
            int dt = d.front();
            
            r.pop();
            d.pop();
            
            if(rt < dt) r.push(rt + n);
            else d.push(dt + n);
        }
        
        return r.size() > d.size() ? "Radiant" : "Dire";
    }
};