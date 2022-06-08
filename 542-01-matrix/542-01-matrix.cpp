class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> ans(r,vector<int> (c,INT_MAX));
        
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            for(pair<int,int> d:dir){
                int nx=x+d.first;
                int ny=y+d.second;
                
                if(nx<0 || nx>=r || ny<0 || ny>=c )
                    continue;
                if(ans[nx][ny]>ans[x][y]+1){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};