class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int fresh =0;
        
        int level=-1;
        
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(pair<int,int> d:dir){
                    int nx=x+d.first;
                    int ny=y+d.second;
                    if(nx<0||nx>=r||ny<0||ny>=c||grid[nx][ny]==2)
                        continue;
                    else if(grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
        }
        if(fresh)
            return -1;
        
        if(level==-1)
            return 0;
        return level ; 
        
    }
};