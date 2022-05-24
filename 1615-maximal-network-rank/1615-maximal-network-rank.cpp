class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        int ans=0;
        for(vector<int> x:roads){
            graph[x[0]].insert(x[1]);
            graph[x[1]].insert(x[0]);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int degree=graph[i].size()+graph[j].size();
                if(graph[i].find(j)!=graph[i].end()){
                    degree--;
                    
                }
                ans=max(ans,degree);
            }
        }
        return ans;
    }
};