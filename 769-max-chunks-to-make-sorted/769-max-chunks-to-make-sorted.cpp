class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int n = v.size();
        int chunks = 0;
        int curr_mx;
        int i = 0;
        while(i < n){
            curr_mx = v[i];
            while(i <= curr_mx){
                if(v[i] > curr_mx) curr_mx = v[i];
                ++i;
                
            }
            ++chunks;
        }
        return chunks;
    }
};