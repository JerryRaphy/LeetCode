class TicTacToe {
public:
    
    bool winner_found;
    vector<int> rows;
    vector<int> cols;
    
    int diagonal;
    int antidiagonal;
    
    int n;
    
    TicTacToe(int n) {
        
        this->n = n;
        rows.resize(n,0);
        cols.resize(n,0);
        winner_found = false;
        diagonal = 0;
        antidiagonal = 0;
        
    }
    
    int move(int row, int col, int player) {
        
        if(winner_found) return 0;
        
        int currentplayer = player == 1 ? 1 : -1;
        rows[row] += currentplayer;
        cols[col] += currentplayer;
        
        if(row == col) diagonal += currentplayer;
        if(col == n - row - 1) antidiagonal += currentplayer;
        
        if(n == abs(rows[row]) ||
           n == abs(cols[col]) || 
           abs(diagonal) == n || 
           abs(antidiagonal) == n){
           
            winner_found = true;
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */