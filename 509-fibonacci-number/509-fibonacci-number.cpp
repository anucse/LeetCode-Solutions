class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int ans;
        int prev2=0;
        int prev1=1;
        for(int i=2;i<=n;i++){
            ans=prev2+prev1;
            prev2=prev1;
            prev1=ans;
        }
        
        return ans;
    }
};