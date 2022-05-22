class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        set<pair<int,int>> visited; // {node,mask}
        queue<pair<pair<int,int>,int>> q; // {{node,mask},distance}
        int all =(1<<n)-1; // 1111...111
        
        for(int i=0;i<n;i++){
            q.push({{i,(1<<i)},1});
            visited.insert({i,(1<<i)});
        }
        
        while(!q.empty()){
            pair<pair<int,int>,int> top=q.front();
            q.pop();
            
            if(top.first.second==all)
                return top.second-1;
            
            for(int x:graph[top.first.first]){
                int bothVisited=top.first.second | (1<<x);
                
                if(visited.find({x,bothVisited})==visited.end()){
                    visited.insert({x,bothVisited});
                    q.push({{x,bothVisited},top.second+1});
                }
            }
        }
        return -1;
    }
};