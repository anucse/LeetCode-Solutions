class Solution {
private:
    
    vector<bool> visited;
    
    bool solve(vector<int>& nums,int target,int currSum,int i,int sides){
        
        if(sides==0)
            return true;
        
        if(currSum==target)
            return solve(nums,target,0,0,sides-1);
        
        //if(currSum>target)
         //   return false;
        
        for(int j=i;j<nums.size();j++){
            if(target<nums[j] || visited[j])
                continue;
            visited[j]=true;
            if(solve(nums,target,currSum+nums[j],j+1,sides))
                return true;
            visited[j]=false;
        }
        
        return false;
    }
    
public:
    
    bool makesquare(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        
        if(nums.size()<4 || sum % 4)
            return false;
        
        int target=sum/4;
        
        visited.resize(nums.size(),false);
        
        return solve(nums,target,0,0,4);
        
    }
};