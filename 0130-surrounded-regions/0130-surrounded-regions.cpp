class Solution {
public:
    void solve(vector<vector<char>>& board,int m,int n,int i, int j,char newChar){
        if(i<0||j<0||i>=m||j>=n||board[i][j]==newChar||board[i][j]=='X')
            return;
        board[i][j]=newChar;
        solve(board,m,n,i+1,j,newChar);
        solve(board,m,n,i-1,j,newChar);
        solve(board,m,n,i,j+1,newChar);
        solve(board,m,n,i,j-1,newChar);
        
    }
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        
        //convert O to *
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' )
                solve(board,m,n,i,0,'*');
            if(board[i][n-1]=='O' )
                solve(board,m,n,i,n-1,'*');
        }
        
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' )
                solve(board,m,n,0,j,'*');
            if(board[m-1][j]=='O' )
                solve(board,m,n,m-1,j,'*');
        }
        
        // DFS for remaining board
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    solve(board,m,n,i,j,'X');
                }
            }
        }
        
        // convert * to O
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='*' )
                solve(board,m,n,i,0,'O');
            if(board[i][n-1]=='*' )
                solve(board,m,n,i,n-1,'O');
        }
        
        for(int j=0;j<n;j++){
            if(board[0][j]=='*' )
                solve(board,m,n,0,j,'O');
            if(board[m-1][j]=='*' )
                solve(board,m,n,m-1,j,'O');
        }
        
    }
};