class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;

        long binaryform=n;
        if(n<0){
            x=1/x;
            binaryform=-1*binaryform;
        }
        while(binaryform>0){
            if(binaryform%2==1){
                ans*=x;
            }

            x*=x;
            binaryform/=2;
        }

        return ans;
    }
};