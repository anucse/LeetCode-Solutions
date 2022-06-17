class Solution {
public:
    // Topological sorting 
    // start from minimum indegree nodes , they are leaf nodes 
    // remove leaves 
    // at last , remaining one or two nodes are the root of min height tree 
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> ans;
        if(n==1)
            return {0};
        // create an indegree vector 
        vector<int> indegree(n,0);
        for(vector x:edges){
            indegree[x[0]]++;
            indegree[x[1]]++;
        }
        
        // create an adjacency graph 
        vector<vector<int>> graph(n);
        for(vector<int> x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        // BFS approach , create a queue 
        queue<int> q;
        
        //push all the leaf nodes(nodes with indegree 1) into the queue
        for(int i=0;i<n;i++){
            if (indegree[i]==1)
                q.push(i);
        }
        
        int s;
        while(!q.empty()){
            ans.clear();
            s=q.size();
    
            for(int i=0;i<s;i++){
                int top=q.front();
                q.pop();
                ans.push_back(top);
                for(int x:graph[top]){
                    indegree[x]--;
                    if(indegree[x]==1) // if becomes leaf
                        q.push(x);
                }
            }
        }
        
         
        return ans;
        
    }
};