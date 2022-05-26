class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> indegree;
    
    void dfs(int node){
        
        indegree[node]=-1;
        for(int x: graph[node]){
            indegree[x]-=1;
            if(indegree[x]==0){
                ans.push_back(x);
                dfs(x);
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        graph.resize(n);
        indegree.resize(n,0);
        
        for(vector<int> x:pre){
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        for(int i=0;i<n;++i){
            if(indegree[i]==0){
                ans.push_back(i);
                dfs(i);
            }
                
        }
        
        if(ans.size()==n)
            return ans;
        return {};
    }
};