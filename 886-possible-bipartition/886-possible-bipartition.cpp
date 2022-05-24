class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(vector<int> x: dislikes){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        queue<int> q;
        vector<int> color(n+1,0);
        for(int i=0;i<n;i++){
            if(color[i]!=0)
                continue;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int top=q.front();
                q.pop();
                for(int node:graph[top]){
                    if(color[node]==color[top])
                        return false;
                    if(color[node]==0){
                        color[node]=color[top]*-1;
                        q.push(node);
                    }
                }
            }
        }
        return true;
    }
};