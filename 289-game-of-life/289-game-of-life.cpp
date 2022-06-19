class Solution {
public:
    // newly alive -> 2 (previously it was dead)
    // newly dead -> 3 (previously it was alive)
    
    
    int getAlive(vector<vector<int>>& board,int i,int j,int r,int c){
        
        int alive=0;
        
        //up
        if(i>0){
            if(board[i-1][j]==1 || board[i-1][j]==3)
                alive++;
        }
        
        //left
        if(j>0){
            if(board[i][j-1]==1 || board[i][j-1]==3)
                alive++;
        }
        
        //down
        if(i<r-1){
            if(board[i+1][j]==1 || board[i+1][j]==3)
                alive++;
        }
        
        //right
        if(j<c-1){
            if(board[i][j+1]==1 || board[i][j+1]==3)
                alive++;
        }
        
        //up-left
        if(i>0 && j>0){
            if(board[i-1][j-1]==1 || board[i-1][j-1]==3)
                alive++;
        }
        
        //up-right
        if(i>0 && j<c-1){
            if(board[i-1][j+1]==1 || board[i-1][j+1]==3)
                alive++;
        }
        
        //down-left
        if(i<r-1 && j>0){
            if(board[i+1][j-1]==1 || board[i+1][j-1]==3)
                alive++;
        }
        
        //down-right
        if(i<r-1 && j<c-1){
            if(board[i+1][j+1]==1 || board[i+1][j+1]==3)
                alive++;
        }
        
        return alive;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int ln=getAlive(board,i,j,r,c);
                if(board[i][j]==0){
                    if(ln==3){
                        board[i][j]=2;
                    }
                }
                else if(board[i][j]==1){
                    if(ln<2 || ln>3){
                        board[i][j]=3;
                    }
                }
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};