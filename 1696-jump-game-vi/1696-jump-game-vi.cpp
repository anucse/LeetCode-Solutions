// time : O(nlogn)  , space : O(n)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        
        priority_queue<pair<int,int>> pq; // {score,index}
        
        pq.push({nums[0],0});
        
        int ans;
        
        for(int i=1;i<n;i++){
            while(i>k && (i-k-1)>=pq.top().second )
                pq.pop();
            pair<int,int> top=pq.top();
            int highestScore=top.first;
            
            pq.push({highestScore+nums[i],i});
            if(i==n-1)
                ans= highestScore+nums[i];
        }
        return ans;
    }
};