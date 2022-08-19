class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int posLen=0;
        int negLen=0;
        int ans=INT_MIN;
        
        for(int x:nums){
            
            if(x==0){
                posLen=0;
                negLen=0;
            }
            
            else if(x<0){
                swap(posLen,negLen);
                negLen++;
                if(posLen)
                    posLen++;
            }
            
            else if(x>0){
                posLen++;
                if(negLen)
                    negLen++;
            }
            
            ans=max(ans,posLen);
        }
        
        return ans;
    }
};