class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
            
        int n = v.size();
        int m = v[0].size();
        
        int l = 0;
        int r = m - 1;
        
        while(l <= r){
            
            int mid = l + (r - l) / 2;
            
            int idx = 0; // row for mid'th col
            int mx_element = v[0][mid];
            
            for(int i=1 ; i<n ; ++i){
                if(v[i][mid] > mx_element){
                    mx_element = v[i][mid];
                    idx = i;
                }
            }
            
            if( (mid == 0 || v[idx][mid-1] < mx_element) && (mid == m - 1 || v[idx][mid+1] < mx_element) ){
                return {idx,mid};
            }
            
            if(mid != 0 && v[idx][mid-1] > mx_element){
                r = mid - 1;
            }
            else l = mid + 1;
            
        }
        
        return {-1,-1};
    }
};