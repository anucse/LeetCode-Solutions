class Solution {
public:
    vector<int> dp;
    
    int recursion(vector<vector<int>> &jobs,int curr_index,int prev_end){
        
        // if no more jobs left
        if(curr_index==jobs.size())
            return 0;
        
        // if current job starts before previous job ends then exclude current job
        if(jobs[curr_index][0]<prev_end)
            return recursion(jobs,curr_index+1,prev_end);
        
        
        if(dp[curr_index]!=-1)
            return dp[curr_index];
        
        int res=max(jobs[curr_index][2]+recursion(jobs,curr_index+1,jobs[curr_index][1]),recursion(jobs,curr_index+1,prev_end));
        
        return dp[curr_index]=res;
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        
        int n=start.size();
        vector<vector<int>> jobs(n,vector<int>(3));
        
        for(int i=0;i<n;i++){
            jobs[i][0]=start[i];
            jobs[i][1]=end[i];
            jobs[i][2]=profit[i];
        }
        
        sort(jobs.begin(),jobs.end());
        
        dp.resize(n,-1);
        
        return recursion(jobs,0,0);
    }
};