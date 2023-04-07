class Solution {
public:
    int find(vector<int> &parent, int x){
        if(parent[x]==x)
            return x;
        return find(parent,parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        if(n==0)
            return {};
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<n;i++){
            int par1=find(parent,edges[i][0]);
            int par2=find(parent,edges[i][1]);
            if(par1==par2)
                return edges[i];
            parent[par2]=par1;
        }
        
        return {};
    }
};