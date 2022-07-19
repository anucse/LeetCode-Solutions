class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
            int mod=n%2;
            ans=ans*2+mod;
            n=n/2;
        }
        
        return ans;
    }
};