class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positive=0;
        int negative=0;
        int ans=0;
        for(int x:nums){
            if(x==0){
                positive=negative=0;
            }
            else if(x<0){
                swap(positive,negative);
                if(positive)
                    positive++;
                negative++;
            }
            else if(x>0){
                positive++;
                if(negative)
                    negative++;
            }
            
            ans=max(ans,positive);
        }
        return ans;
    }
};