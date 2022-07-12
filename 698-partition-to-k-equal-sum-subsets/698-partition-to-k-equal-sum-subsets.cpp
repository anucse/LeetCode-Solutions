class Solution {
private:
    vector<bool> visited;
    bool solve(vector<int>& nums,int target,int currSum,int i, int k){
        if(k==1)
            return true;
        if(i>=nums.size())
            return false;
        if(currSum==target)
            return solve(nums,target,0,0,k-1);
        for(int j=i;j<nums.size();j++){
            if(visited[j] || target<currSum+nums[j])
                continue;
            
            visited[j]=true;
            if(solve(nums,target,currSum+nums[j],j+1,k))
                return true;
            visited[j]=false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int x:nums)
            sum+=x;
        if( sum%k)
            return false;
        visited.resize(nums.size(),false);
        sort(begin(nums),end(nums),greater<int>());
        return solve(nums,sum/k,0,0,k);
    }
};