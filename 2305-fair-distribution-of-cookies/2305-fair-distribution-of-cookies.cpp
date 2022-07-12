class Solution {
private:
    vector<int> sum;
    int ans=INT_MAX;
    
    void solve(vector<int>& nums,int i,int k){
        if(i==nums.size()){
            int maximum=*max_element(sum.begin(),sum.end());
            ans=min(ans,maximum);
            return ;
        }
        
        for(int j=0;j<k;j++){
            sum[j]+=nums[i];
            solve(nums,i+1,k);
            sum[j]-=nums[i];
            if(sum[j]==0)
                break;
        }
        
    }
public:
    int distributeCookies(vector<int>& nums, int k) {
        sum.resize(k,0);
        solve(nums,0,k);
        return ans;
    }
};