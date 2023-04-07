class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        
        for(auto &x: pre){
            adj[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }
        
        vector<int> ans;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            
            for(auto &x: adj[top]){
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push(x);
                }
            }
        }
        
        if(ans.size()==n)
            return ans;
        return {};
    }
};