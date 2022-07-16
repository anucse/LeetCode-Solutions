class Solution {
public:
    void solve(vector<vector<int>>& image,int i,int j,int oldColor,int newColor){
        int r=image.size();
        int c=image[0].size();
        
        if(i>=r || j>=c || i<0||j<0||image[i][j]!=oldColor||image[i][j]==newColor)
            return;
        
        image[i][j]=newColor;
        
        solve(image,i+1,j,oldColor,newColor);
        solve(image,i-1,j,oldColor,newColor);
        solve(image,i,j+1,oldColor,newColor);
        solve(image,i,j-1,oldColor,newColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(image,sr,sc,image[sr][sc],color);
        return image;
    }
};