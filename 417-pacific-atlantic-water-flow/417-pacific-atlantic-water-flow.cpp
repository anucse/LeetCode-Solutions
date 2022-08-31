class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<bool>> &ocean,int r,int c, int i, int j){
        
        if(ocean[i][j])
            return ;
        ocean[i][j]=true;
        
        if(i+1<r && heights[i+1][j]>=heights[i][j])
            dfs(heights,ocean,r,c,i+1,j);
        
        if(i-1>=0 && heights[i-1][j]>=heights[i][j])
            dfs(heights,ocean,r,c,i-1,j);
        
        if(j+1<c && heights[i][j+1]>=heights[i][j])
            dfs(heights,ocean,r,c,i,j+1);
        
        if(j-1>=0 && heights[i][j-1]>=heights[i][j])
            dfs(heights,ocean,r,c,i,j-1);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int r=heights.size();
        int c=heights[0].size();
        
        vector<vector<bool>> pacific(r,vector<bool>(c,false));
        vector<vector<bool>> atlantic(r,vector<bool>(c,false));
        vector<vector<int>> ans;
        
        for(int j=0;j<c;j++){
            dfs(heights,pacific,r,c,0,j);
            dfs(heights,atlantic,r,c,r-1,j);
        }
        for(int i=0;i<r;i++){
            dfs(heights,pacific,r,c,i,0);
            dfs(heights,atlantic,r,c,i,c-1);
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(atlantic[i][j] && pacific[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};