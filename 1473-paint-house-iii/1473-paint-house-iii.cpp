

class Solution {
    int INF=1000001;
public:
    int solve(vector<int>& houses, vector<vector<int>>& cost,vector<vector<vector<int>>>& dp, int h, int n,int target,int i,int nbrhood,int left){
        
        if(i==h)
            return (target==nbrhood)?0:INF;
        
        if(nbrhood>target)
            return INF;
        
        if(dp[i][nbrhood][left]!=-1)
            return dp[i][nbrhood][left];
        
        if(houses[i]==0){
            int minCost=INF;
            for(int c=1;c<=n;c++){
                int newNbrhood=nbrhood;
                if(c!=left)
                    newNbrhood=nbrhood+1;
                minCost=min(minCost,solve(houses,cost,dp,h,n,target,i+1,newNbrhood,c)+cost[i][c-1]);
            }
            return dp[i][nbrhood][left]=minCost;
        }
        
        else {
            int newNbrhood=nbrhood;
            if(left!=houses[i])
                newNbrhood=nbrhood+1;
            return dp[i][nbrhood][left]=solve(houses,cost,dp,h,n,target,i+1,newNbrhood,houses[i]);
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int h, int n, int target) {
        vector<vector<vector<int>>> dp(h,vector<vector<int>>(target+1,vector<int>(n+1,-1)));
        
        int ans=solve(houses,cost,dp,h,n,target,0,0,0);
        if(ans==INF)
            return -1;
        else
           return ans; 
    }
};