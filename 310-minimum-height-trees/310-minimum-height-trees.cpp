class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        
        vector<int> ans;
        
        vector<vector<int>> graph(n);
        vector<int> degree(n,0);
        
        for(vector<int> x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                q.push(i);
        }
        
        while(!q.empty()){
            int s=q.size();
            ans.clear();
            for(int i=0;i<s;i++){
                int top=q.front();
                q.pop();
                ans.push_back(top);
                for(int x:graph[top]){
                    degree[x]-=1;
                    if(degree[x]==1)
                        q.push(x);
                }
            }
        }
        return ans;
    }
};