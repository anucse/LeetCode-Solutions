class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        
        int r=height.size();
        int c=height[0].size();
        
       // {height[i],{i,j}} 
               priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> visited(r,vector<int> (c,false));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0 || i==r-1 || j==c-1){
                    pq.push({height[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=0;
        
        while(!pq.empty()){
            int val=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            
            for(pair<int,int> d:dir){
                int nx=x+d.first;
                int ny=y+d.second;
                if(nx<0||nx>=r||ny<0||ny>=c||visited[nx][ny])
                    continue;
                visited[nx][ny]=true;
                ans+=max(0,val-height[nx][ny]);
                pq.push({max(val,height[nx][ny]),{nx,ny}});
            }
        }
        return ans;
        
    }
};