class Solution {
public:
    int minimumTotal(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
        int ans=INT_MAX;
        //vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        vector<int> prev(n,INT_MAX),curr(n,INT_MAX);
        
        prev[0]=matrix[0][0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    curr[j]=prev[j]+matrix[i][j];
                }
                
                else{
                    curr[j]=min(prev[j],prev[j-1])+matrix[i][j];
                }
            }
            prev=curr;
        }
        
        for(int j=0;j<n;j++){
            ans=min(ans,prev[j]);
        }
        
        return ans;
    }
};