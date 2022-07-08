class Solution {
    int INF=1000001;
    vector<vector<vector<int>>>dp;
public:
    // index , target , right color 
    int solve(vector<int>& houses, vector<vector<int>>& cost, int h,int n, int target,int i,int right){
        if(i<0){
            if(target==0)
                return 0;
            else 
                return INF;
        }
        if(target<0)
            return INF;
        
        if(dp[i][target][right]!=-1)
            return dp[i][target][right];
        
        if(houses[i]==0){ // not painted 
            int minCost=INF;
            for(int c=1;c<=n;++c){
                if(c==right)
                    minCost=min(minCost,solve(houses,cost,h,n,target,i-1,c)+cost[i][c-1]);
                else 
                    minCost=min(minCost,solve(houses,cost,h,n,target-1,i-1,c)+cost[i][c-1]);
            }
            return dp[i][target][right]=minCost;
            
        }
        
        else{  //already painted 
            if(houses[i]==right)
                return dp[i][target][right]=solve(houses,cost,h,n,target,i-1,houses[i]);
            else 
                return dp[i][target][right]=solve(houses,cost,h,n,target-1,i-1,houses[i]);
            
        }
        
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int h, int n, int target) {
        dp.resize(h,vector<vector<int>>(target+1,vector<int>(n+1,-1)));
        int ans =solve(houses,cost,h,n,target,h-1,0);
        if(ans==INF)
            return -1;
        return ans;
    }
};