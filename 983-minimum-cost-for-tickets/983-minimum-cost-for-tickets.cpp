class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,vector<int>& dp, int n, int i){
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        // 1 day pass 
        
        int oneDay=costs[0]+solve(days,costs,dp,n,i+1);
        
        // 7 days pass
        
        int j ;
        for(j=i;j<n && days[j]<days[i]+7;j++);
        
        int sevenDay=costs[1]+solve(days,costs,dp, n,j);
                    
        // 30 days pass 
        
        
        for(j=i;j<n && days[j]<days[i]+30;j++);
        
        int thirtyDay=costs[2]+solve(days,costs,dp, n,j);
        
        return dp[i]= min({oneDay,sevenDay,thirtyDay});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(367,-1);
        int n=days.size();
        return solve (days,costs,dp,n,0);
    }
};