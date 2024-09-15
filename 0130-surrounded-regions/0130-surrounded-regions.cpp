class Solution {
private:
    int m;
    int n;
public:

    void dfs(vector<vector<char>>& board,int i, int j,char newChar){
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='X')
            return;
        board[i][j]=newChar;
        dfs(board,i+1,j,newChar);
        dfs(board,i-1,j,newChar);
        dfs(board,i,j+1,newChar);
        dfs(board,i,j-1,newChar);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        
        // protect the sides
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                
                dfs(board,i,0,'*');
            }
            if(board[i][n-1]=='O'){
                
                dfs(board,i,n-1,'*');
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                
                dfs(board,0,j,'*');
            }
            if(board[m-1][j]=='O'){
                dfs(board,m-1,j,'*');
            }
        }

        // dfs
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    dfs(board,i,j,'X');
                }
            }
        }

        // restore 0
         for(int i=0;i<m;i++){
            if(board[i][0]=='*'){
                
                dfs(board,i,0,'O');
            }
            if(board[i][n-1]=='*'){
                
                dfs(board,i,n-1,'O');
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='*'){
                
                dfs(board,0,j,'O');
            }
            if(board[m-1][j]=='*'){
                
                dfs(board,m-1,j,'O');
            }
        }

        
    }
};