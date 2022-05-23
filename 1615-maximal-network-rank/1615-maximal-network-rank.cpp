class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int degree_sum,ans=0;
        vector<unordered_set<int>> graph(n);
        for(vector<int> x:roads){
            graph[x[0]].insert(x[1]);
            graph[x[1]].insert(x[0]);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                degree_sum=graph[i].size()+graph[j].size();
                if(graph[i].find(j)!=graph[i].end())
                    degree_sum-=1;
                ans=max(ans,degree_sum);
            }
        }
        
        return ans;
    }
};