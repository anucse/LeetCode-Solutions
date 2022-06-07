class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(vector<int> x:times){
            graph[x[0]].push_back({x[1],x[2]}); // {destination,distance}
        }
        
        queue<int> q;
        vector<int> dist(n+1,INT_MAX);
        
        q.push(k);
        dist[k]=0;
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            for(pair<int,int> x:graph[top]){
                if(dist[x.first]>dist[top]+x.second){
                    dist[x.first]=dist[top]+x.second;
                    q.push(x.first);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};