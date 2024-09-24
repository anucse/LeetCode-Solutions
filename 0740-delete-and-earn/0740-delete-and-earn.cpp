class Solution {
public:
    const int N=(1e4);
    vector<int> dp;

    int solve(int i, vector<int>& nums,vector<int>& freq){

        if(i>=N){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        

        int np=solve(i+1,nums,freq);
        int p=i*freq[i]+solve(i+2,nums,freq);

        dp[i]=max(p,np);

        return dp[i];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(N,0);
        dp.resize(N,-1);

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        return solve(1,nums,freq);
    }
};