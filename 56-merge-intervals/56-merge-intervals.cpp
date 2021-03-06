class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int m=0;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(ans[m][1]>=intervals[i][0]){
                ans[m][1]=max(ans[m][1],intervals[i][1]);
                
            }
            else{
                m++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
