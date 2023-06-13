// negative values need to be crushed down

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        bool game = true;
        

        while(game){
            
            game = false;
            
            for(int i=0 ; i<n ; ++i){
                for(int j=0 ; j<m ; ++j){
                    
                    if(board[i][j] == 0) continue;
                    int value = abs(board[i][j]);
                    
                    // checking rightward direction
                    if(j < m - 2 && value == abs(board[i][j+1]) && value == abs(board[i][j+2])){
                        game = true;
                        int k = j;
                        while(k < m && value == abs(board[i][k])){
                            board[i][k] = value * -1;
                            k += 1;
                        }
                    }
                       
                       
                    // checking downward direction
                    if(i < n - 2 && value == abs(board[i+1][j]) && value == abs(board[i+2][j])){
                        game = true;
                        int k = i;
                        while(k < n && value == abs(board[k][j])){
                            board[k][j] = value * -1;
                            k += 1;
                        }
                    }
                    
                }
            }
            
            if(game){
                for(int j=0 ; j<m ; ++j){
                    int lastrow = n - 1;
                    for(int i=n-1 ; i>=0 ; --i){
                        if(board[i][j] > 0){
                            board[lastrow][j] = board[i][j];
                            lastrow -= 1;
                        }
                    }
                    
                    for(int k=lastrow ; k>=0 ; --k) board[k][j] = 0;
                }
            }
        }
        
        return board;
    }
};