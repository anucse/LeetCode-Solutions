class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(10001,0);
        
        for(int x:nums){
            count[x]++;
        }
        
        
        
        int prev2=count[1];
        int prev1=max(count[2]*2,count[1]);
        int ans;
        
        for(int i=3;i<=10000;i++){
            ans=max(prev1,prev2+count[i]*i);
            prev2=prev1;
            prev1=ans;
        }
        
        return prev1;
        
    }
};