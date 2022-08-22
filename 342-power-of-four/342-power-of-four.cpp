class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        while(n>1){
            int rem=n%4;
            n=n/4;
            if(rem!=0)
                return false;
        }
        
        return true;
    }
};