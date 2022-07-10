class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1 || n==0)
            return n;
        
        for(long i=1;i<=n;i++){
            long long a=i*(i+1)/2;
            if(a>n)
                return i-1;
        }
        return 0;
    }
};