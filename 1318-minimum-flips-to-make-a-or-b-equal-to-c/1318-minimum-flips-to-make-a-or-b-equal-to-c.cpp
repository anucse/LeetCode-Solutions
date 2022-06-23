class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ans=0;
        
        while(a || b||c){
            bool a1=(a&1);
            bool b1=(b&1);
            bool c1=(c&1);
            
            bool aorb = a1 | b1;
            
            if(aorb != c1){
                // aorb -> 0 , c1 -> 1
                if(c1==1){         
                    ans++;
                }
                else if(c1==0) {
                    if(a1==1 && b1==1)
                        ans+=2;
                    else 
                        ans++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        
        return ans;
        
    }
};