class Solution {
public:
    
    bool static comp(vector<int> &A, vector<int> &B){
        if(A[1] == B[1]) return A[0] < B[0];
        return A[1] < B[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp); 
        
        int arrows = 1;
        int n = points.size();
        int shoot_at = points[0][1];
        
        //for(int i=0 ; i<n ; ++i) cout<<points[i][0]<<" "<<points[i][1]<<endl;
        
        for(int i=1;  i<n ; ++i){
            if(points[i][0] > shoot_at){
                ++arrows;
                shoot_at = points[i][1];
            }
        }
        return arrows;
    }
};