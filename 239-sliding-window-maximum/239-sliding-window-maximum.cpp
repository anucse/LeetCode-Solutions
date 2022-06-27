class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq; //{value,index}
        int l=0;
        int r=0;
        vector<int> ans;
        while(r<n){
            pq.push({nums[r],r});
            if(r-l+1<k){
                r++;
            }
            else if(r-l+1==k){
                while(pq.top().second<l){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                l++;
                r++;
            }
        }
        return ans;
    }
};