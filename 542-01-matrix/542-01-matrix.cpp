class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> ans(r,vector<int>(c,INT_MAX));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            
            q.pop();
            
            for(pair<int,int> d:dir){
                int nx=x+d.first;
                int ny=y+d.second;
                
                if(nx<0 || nx>=r || ny<0 || ny>=c)
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