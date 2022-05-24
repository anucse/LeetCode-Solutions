class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int> q;
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++){
            if(color[i]!=0)
                continue;
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                int top=q.front();
                q.pop();
                for(int x:graph[top]){
                    if(!color[x]){
                        color[x]=color[top]*-1;
                        q.push(x);
                    }
                    else if(color[x]==color[top])
                        return false;
                }
            }
        }
        return true;
    }
};