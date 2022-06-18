class Solution {
public:
    void dfs(vector<vector<char>>& board,char target,int i,int j,int r,int c){
        if(i<0||i>=r||j<0||j>=c||board[i][j]=='X')
            return ;
        if(target=='1'){
            if(board[i][j]=='1')
                return ;
        }
        if(target=='O'){
            if(board[i][j]=='O')
                return ;
        }
        
        board[i][j]=target;
        
        dfs(board,target,i+1,j,r,c);
        dfs(board,target,i-1,j,r,c);
        dfs(board,target,i,j+1,r,c);
        dfs(board,target,i,j-1,r,c);
        
    }
    
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        
        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){
                dfs(board,'1',i,0,r,c);
            }
            if(board[i][c-1]=='O'){
                dfs(board,'1',i,c-1,r,c);
            }
        }
        
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                dfs(board,'1',0,i,r,c);
            }
            if(board[r-1][i]=='O'){
                dfs(board,'1',r-1,i,r,c);
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        
        for(int i=0;i<r;i++){
            if(board[i][0]=='1'){
                dfs(board,'O',i,0,r,c);
            }
            if(board[i][c-1]=='1'){
                dfs(board,'O',i,c-1,r,c);
            }
        }
        
        for(int i=0;i<c;i++){
            if(board[0][i]=='1'){
                dfs(board,'O',0,i,r,c);
            }
            if(board[r-1][i]=='1'){
                dfs(board,'O',r-1,i,r,c);
            }
        }
    }
        
};