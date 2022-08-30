class Solution {
public:
    void transpose(vector<vector<int>> &matrix,int n){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int l=0;
        int r=n-1;
        
        transpose(matrix,n);
        
        for(int i=0;i<n;i++){
            while(l<r){
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
            l=0;
            r=n-1;
        }
    }
};