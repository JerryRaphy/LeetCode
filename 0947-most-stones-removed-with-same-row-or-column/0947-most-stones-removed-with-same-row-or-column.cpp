class Solution {
public:
    
    class UnionOp{
        public:
        unordered_map<int,int> parent;
        unordered_map<int,int> sz;
        int cnt = 0;
        
        UnionOp(vector<vector<int>> stones){
            for(auto a : stones){
                int row = -(a[0] + 1);
                int col = a[1] + 1;
                parent[row] = row;
                parent[col] = col;
                
                sz[row] = 1;
                sz[col] = 1;
            }
            cnt = parent.size();
        }
        
        
        int findParent(int stone){
            if(parent[stone] == stone) return stone;
            return parent[stone] = findParent(parent[stone]);
        }
        
        void performUnion(int a, int b){
            a = findParent(a);
            b = findParent(b);
            
            if(a == b) return;
            --cnt;
            
            if(sz[b] > sz[a]) swap(a,b);
            parent[b] = a;
            sz[a] += b;
            return;
        }
        
    };
        
    int removeStones(vector<vector<int>>& stones) {
        UnionOp up(stones);
        for(auto stone : stones){
            int r = -(stone[0] + 1);
            int c = stone[1] + 1;
            up.performUnion(r,c);
        }
        return stones.size() - up.cnt;
    }
};