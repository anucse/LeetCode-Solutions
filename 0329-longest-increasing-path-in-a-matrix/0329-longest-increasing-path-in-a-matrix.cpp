class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& matrix,int m,int n,int i,int j){
        
        if(i<0 || j<0 || i>=m || j>=n )
            return 0;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up=0,down=0,left=0,right=0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j] ){
            up=solve(matrix,m,n,i-1,j)+1;
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j] ){
            left=solve(matrix,m,n,i,j-1)+1;
        }
        if(i+1<m && matrix[i+1][j]>matrix[i][j] ){
            down=solve(matrix,m,n,i+1,j)+1;
        }
        if(j+1<n && matrix[i][j+1]>matrix[i][j] ){
            right=solve(matrix,m,n,i,j+1)+1;
        }
        
        
        
        return dp[i][j]=max(up,max(down,max(left,right)));
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        dp.resize(m,vector<int> (n,-1));
        
        int ans=INT_MIN;
        int len=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1)
                    len=solve(matrix,m,n,i,j)+1;
                ans=max(ans,len);
            }
        }
        return ans;
    }
};