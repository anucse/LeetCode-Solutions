class Solution {
public:
    int countPrimes(int n) {
        int count =0;
        vector<int>nums(n+1,true);
        nums[0]=false;
        if(n>0)
        nums[1]=false;
        for(int i=2;i<=n;i++){
            if(nums[i]==true){
                for(int j=i*i;j<n;j+=i){
                    nums[j]=false;
                }
            }
        }
        nums[n]=false;

        for(auto &x:nums){
            if(x){
                count++;
            }
        }

        return count;
    }
};