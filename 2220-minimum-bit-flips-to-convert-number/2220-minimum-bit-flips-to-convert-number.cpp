class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a= (start^goal);
        int ans=0;
        while(a){
            a=a & (a-1);
            ans++;
        }
        
        return ans;
    }
};