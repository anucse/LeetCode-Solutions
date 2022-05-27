class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target>1){
            if(target%2==0 && maxDoubles){
                target=target>>1;
                maxDoubles-=1;
            }
            else{
                target-=1;
            }
            ans++;
            if(maxDoubles==0)
                return (target-1)+ans;
        }
        return ans;
    }
};