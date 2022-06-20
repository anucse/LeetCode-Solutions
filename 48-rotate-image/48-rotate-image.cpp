class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                int temp=matrix[j][i];
                matrix[j][i]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        
        int l=0;
        int r=matrix[0].size()-1;
        
        while(l<r){
            for(int i=0;i<matrix.size();i++){
                swap(matrix[i][l],matrix[i][r]);
            }
            l++;
            r--;
        }
    }
};