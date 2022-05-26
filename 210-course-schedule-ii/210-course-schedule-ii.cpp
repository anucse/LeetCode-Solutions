class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> indegree;
    
    void dfs(int node){
        ans.push_back(node);
        indegree[node]=-1;
        for(int x:graph[node]){
            indegree[x]-=1;
            if(indegree[x]==0){
                
                dfs(x);
            }
                
        }
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        graph = vector<vector<int>> (n);
        indegree=vector<int> (n,0);
        
        for(vector<int> x:pre){
            indegree[x[0]]++;
            graph[x[1]].push_back(x[0]);
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                dfs(i);
        }
        
        if(ans.size()==n)
            return ans;
        return {};
    }
};