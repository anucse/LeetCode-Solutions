class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans(n);
        int sum=0;
        for(int x:nums){
            if(( x & 1) ==0)
                sum+=x;
        }
        
        for(int i=0;i<n;i++){
            int val=queries[i][0];
            int index=queries[i][1];
            
            int oldVal=nums[index];
            int newVal=oldVal+val;
            
            bool wasEven=(oldVal & 1 )==0;
            bool isEven=(newVal & 1 )==0;
            
            nums[index]=newVal;
            
            if(wasEven && isEven){
                sum-=oldVal;
                sum+=newVal;
            }
            
            else if(!wasEven && isEven )
                sum+=newVal;
            
            else if(wasEven && !isEven)
                sum-=oldVal;
            
            ans[i]=sum;
        }
        
        return ans;
        
    }
};