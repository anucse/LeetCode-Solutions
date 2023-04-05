class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        // vector<vector<int>> dp(m,vector<int> (n,0));
        vector<int> prev(n,1),curr(n,1);
        
        
//         for(int i=0;i<m;i++){
//             dp[i][n-1]=1;
//         }
        
//         for(int j=0;j<n;j++){
//             dp[m-1][j]=1;
//         }
        
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j==n-1)
                    curr[j]=1;
                else{
                    int right=curr[j+1];
                    int down= prev[j];
                    curr[j]=right+down;
                }

                
            }
            prev=curr;
        }
        
        return curr[0];
    }
};