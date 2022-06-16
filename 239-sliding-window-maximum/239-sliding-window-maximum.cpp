class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        int left=0;
        int right=0;
        vector<int> res;
        
        while(right<nums.size()){
            q.push({nums[right],right});
            
            if(right-left+1<k){
                right++;
            }
            
            else if(right-left+1==k){
                while(q.top().second<left){
                    q.pop();
                }
                
                res.push_back(q.top().first);
                
                left++;
                right++;
            }
        }
        return res;
    }
};