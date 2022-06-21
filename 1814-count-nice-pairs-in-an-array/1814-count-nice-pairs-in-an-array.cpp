class Solution {
public:
    
    long C2(long n){
        return (n*(n-1))/2;
    }
    
    long rev(long n){
        long ans=0;
        while(n){
            
            ans=ans*10+(n%10);
            n=n/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[i]-rev(nums[i]));
        }
        
        unordered_map<long,long> m; // num [i] - rev(num[i]) -> count 
        
        for(auto x:nums){
            m[x]++;
        }
        
        long ans=0;
        
        for(auto x:m){
            if(x.second>0){
                ans+=C2(x.second);
            }
        }
        return ans % (1000000000+7);
    }
};