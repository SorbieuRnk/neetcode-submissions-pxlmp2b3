class TicTacToe {
public:
  vector<vector<int>>grid;
    TicTacToe(int n) {
       grid.resize(n);
       for(auto &i:grid){
        i.resize(n);
       }
    }
  
    int move(int row, int col, int player) {
        int n=grid.size();
        grid[row][col]=player;
        bool up=true;
        int uprow=0;
        while(uprow<n){
            if(grid[uprow][col]!=player){
             up=false;
             break;
            }
            uprow++;
        }
bool side=true;
        int sidecol=0;
        while(sidecol<n){
            if(grid[row][sidecol]!=player){
                side=false;
                break;
            }
            sidecol++;
        }

        int diagrow1=0,diagcol1=0;
        bool diag1=true;
        while(diagrow1<n&&diagcol1<n){
            if(grid[diagrow1][diagcol1]!=player){
                diag1=false;
                break;
            }
            diagrow1++,diagcol1++;
        }

        bool diag2=true;
        int diagrow2=0,diagcol2=n-1;
        while(diagrow2<n&&diagcol2>=0){
             if(grid[diagrow2][diagcol2]!=player){
                diag2=false;
                break;
            }
            diagrow2++,diagcol2--;
        }
        if(up||side||diag1||diag2) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
