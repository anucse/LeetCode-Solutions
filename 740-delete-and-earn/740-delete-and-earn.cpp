class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001,0); 
        for(int x:nums){
            count[x]++;
        }
        
        
        int prev2=count[0];
        int prev1=count[1];
        
        int ans;
        
        
        for(int i=2;i<=10000;i++){
            ans=max(prev1,(count[i]*i)+prev2);
            prev2=prev1;
            prev1=ans;
        }
        
        return ans;
    }
};