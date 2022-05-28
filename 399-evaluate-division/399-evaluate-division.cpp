class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> graph;
    unordered_map<string,bool>visited;
    
    double queryAns;
    
    bool dfs(string start,string end,double current){
        if(start==end && graph.find(start)!=graph.end()){
            queryAns=current;
            return true;
        }
        
        bool temp=false;
        visited[start]=true;
        
        for(int i=0;i<graph[start].size();i++){
            if(!visited[graph[start][i].first]){
                temp=dfs(graph[start][i].first,end,current*graph[start][i].second);
                if(temp)
                    break;
            }
        }
        visited[start]=false;
        
        return temp;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=equations.size();
        int m=queries.size();
        vector<double> ans(m,-1);
        
        
        for(int i=0;i<n;i++){
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1/values[i]});
            visited[equations[i][0]]=visited[equations[i][0]]=false;
        }
        
        for(int i=0;i<m;i++){
            queryAns=1;
            bool found=dfs(queries[i][0],queries[i][1],1);
            if(found)
                ans[i]=queryAns;
            else
                ans[i]=-1;
        }
        return ans;
    }
};