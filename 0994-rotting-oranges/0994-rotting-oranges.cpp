class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        
        int ans=0;
        
        
        while(!q.empty()){
            int s=q.size();
            int t;
            
            while(s--){
                int x=q.front().first.first;
                int y=q.front().first.second;
                t=q.front().second;
                
                q.pop();
                if(x-1>=0 && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({{x-1,y},t+1});
                }
                    
                if(x+1<m && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({{x+1,y},t+1});
                }
                    
                if(y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({{x,y-1},t+1});
                }
                    
                if(y+1<n && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({{x,y+1},t+1});
                }
                    
            }
            
            ans=max(ans,t);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return ans;
        
    }
};