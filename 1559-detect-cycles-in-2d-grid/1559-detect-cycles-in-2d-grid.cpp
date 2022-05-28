class Solution {
public:
    vector<vector<bool>> visited;
    bool dfs(vector<vector<char>>& grid,int i,int j ,int lasti,int lastj,char target){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=target)
            return  false;
        if(visited[i][j] )
            return true;
        visited[i][j]=true;
        if((i+1!=lasti || j!=lastj )&& dfs(grid,i+1,j,i,j,target))return true;
        if((i!=lasti || j+1!=lastj )&& dfs(grid,i,j+1,i,j,target))return true;
        if((i-1!=lasti || j!=lastj )&& dfs(grid,i-1,j,i,j,target))return true;
        if((i!=lasti || j-1!=lastj )&& dfs(grid,i,j-1,i,j,target))return true;
        return  false;
        
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        visited=vector<vector<bool>>(r,vector<bool>(c,false));
        
        bool ans=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && dfs(grid,i,j,-1,-1,grid[i][j])){
                    return true;
                }
                
            }
        }
        return false;
    }
};