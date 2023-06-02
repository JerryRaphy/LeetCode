class Solution {
public:
    
    
    void solve(int node, map<int,vector<int>> &mp, int par, int kill, vector<int> &res){
        
        if(par == kill || node == kill) res.push_back(node);
        for(auto child : mp[node]){
            if(par == kill || node == kill) solve(child,mp,kill,kill,res);
            else solve(child,mp,node,kill,res);
        }
        return;
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        vector<int> res;
        map<int,vector<int>> mp;
        
        int n = ppid.size();
        int root = 0;
        
        for(int i=0 ; i<n ; ++i){
            if(ppid[i] == 0) {
                root = pid[i];
            }
            else mp[ppid[i]].push_back(pid[i]);
        }
        
        solve(root,mp,0,kill,res);
        return res;
        
    }
};