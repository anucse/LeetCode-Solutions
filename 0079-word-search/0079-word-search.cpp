class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int p,int i,int j, int m, int n){
        if(p==word.size())
            return true;
        
        if(i<0||j<0||i>=m||j>=n||word[p]!=board[i][j]||board[i][j]=='*')
            return false;
        
        char c= board[i][j];
        board[i][j]='*';
        
        
        bool up=solve(board,word,p+1,i-1,j,m,n);
        bool down=solve(board,word,p+1,i+1,j,m,n);
        bool left=solve(board,word,p+1,i,j-1,m,n);
        bool right=solve(board,word,p+1,i,j+1,m,n);
        
        board[i][j]=c;
        
        return up||down||left||right;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word,0,i,j,m,n))
                        return true;
                }
            }
        }
        
        return false;
    }
};