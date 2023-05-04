class Solution {
public:
    int m,n;

// Four Directional Co-ordinates.

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

/* fire_time[i][j] stores the minimum time takes to spread the fire from their   
   initial positions to current cell [i,j] */

int fire_time[302][302];

/* dis[i][j] stores the minimum time to reach the cell [i,j] by our hero ,
   by successfully wasting (t) amount of time initially. */

int dis[302][302];



int minimum_time_to_reach_bottom_right(int waste_time,vector<vector<int>>&grid){
    
    queue<pair<int,int>>q;
    
    q.push({0,0});
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=1e9;
        }
    }
    
    dis[0][0]=waste_time; // After wasting (t) amount of time our hero starts his journey from (0,0) cell.
    
    
    while(!q.empty()){
        
        auto curr=q.front();
        q.pop();
        
        int x=curr.first;
        int y=curr.second;
        
        for(int i=0;i<4;i++){
            
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]==2){
                
                continue;
                
            }
            
            int new_min=min(dis[nx][ny],dis[x][y]+1);
            
            if(nx==m-1 && ny==n-1 && new_min<=fire_time[nx][ny]){
                return new_min;
            }
            
            if(new_min>=fire_time[nx][ny]){
                continue;
            }
            
            if(dis[nx][ny]>dis[x][y]+1){
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
            
        }
        
    }
    
    return 1e9+1;
    
    
}



int find_maximum_time(vector<vector<int>>&grid){
    
    // Base Case --> When the fire is not able to reach (m-1,n-1) cell.
    
    if(fire_time[m-1][n-1]==1e9){
        
        if(minimum_time_to_reach_bottom_right(0,grid)>=1e9){
            return -1;
        }
        
        else{
            return 1e9;
        }
        
    }
    
    
    // Binary Search on answer.
    
    int low=0,high=(m*n)+1;
    
    int ans=-1;
    
    while(low<=high){
        
        int mid=(low+high)/2;
        
        if(minimum_time_to_reach_bottom_right(mid,grid)<=fire_time[m-1][n-1]){
            ans=mid;
            low=mid+1;
        }
        
        else{
            high=mid-1;
        }
        
    }
    
    if(ans>=(m*n)+1){
        return 1e9;
    }
    
    else{
        return ans;
    }
    
}


int maximumMinutes(vector<vector<int>>& grid) {
    
    m=grid.size();
    n=grid[0].size();
    
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            fire_time[i][j]=1e9;
        }
    }
    
    
    queue<pair<int,int>>q; // Here we use Multi-Source BFS to calculate the minimum time to reach cell (i,j) from all the initially given fire-points.
    
    
    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
            
            if(grid[i][j]==1){
                
                q.push({i,j});
                
                fire_time[i][j]=0;
                
            }
            
        }
        
    }
    
    
    while(!q.empty()){
        
        auto curr=q.front();
        q.pop();
        
        int x=curr.first;
        int y=curr.second;
        
        for(int i=0;i<4;i++){
            
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=2){
                
                if(fire_time[nx][ny]>fire_time[x][y]+1){
                    
                    fire_time[nx][ny]=fire_time[x][y]+1;
                    
                    q.push({nx,ny});
                    
                }
                
            }
            
        }
        
    }
    
    
    int ans=find_maximum_time(grid);
    
    return ans;
    
}
};