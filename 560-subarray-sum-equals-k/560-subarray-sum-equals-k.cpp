class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        // calculate prefix sum array
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(k==prefix[i])
                ans++;
            if(m.find(prefix[i]-k)!=m.end()){
                ans+=m[prefix[i]-k];
            }
            
            m[prefix[i]]++;
        }
        
        return ans;
    }
};