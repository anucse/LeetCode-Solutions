class Solution {
public:
    
    int change(int target, vector<int>& coins) {
        
        int n=coins.size();
        // vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        vector<int> prev(target+1,0),curr(target+1,0);
        
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                if(j==0){
                    curr[j]=1;
                }
                else{
                    int t=0;
                    if(j>=coins[i])
                        t=curr[j-coins[i]];
                    int nt=prev[j];

                    curr[j]=t+nt;
                }
            }
            prev=curr;
        }
        return curr[target];
        
    }
};