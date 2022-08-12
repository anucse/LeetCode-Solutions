class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;
        int prev1=1;
        int prev2=1;
        int ans;
        for(int i=2;i<=n;i++){
            ans=prev1+prev2;
            prev2=prev1;
            prev1=ans;
        }
        
        return prev1;
    }
};