class Solution {
public:
    vector<int> visited;
    vector<vector<int>> graph;
    
    bool cycle(int i){
        if(visited[i]==1)
            return true;
        if(visited[i]==0){
            visited[i]=1;
            for(int x:graph[i]){
                if(cycle(x))
                    return true;
            }
        }
        visited[i]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        visited=vector<int> (n,0);
        graph=vector<vector<int>>(n);
        
        for(vector<int> x:pre){
            graph[x[1]].push_back(x[0]);
        }
        
        for(int i=0;i<n;i++){
            if(cycle(i))
                return false;
        }
        
        return true;
    }
};