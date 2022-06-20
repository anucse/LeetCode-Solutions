class Solution {
public:
    void transpose(vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    void rotate90(vector<vector<int>>& mat){
        transpose(mat);
        int l=0;
        int r=mat.size()-1;
        while(l<r){
            for(int i=0;i<mat.size();i++){
                swap(mat[i][l],mat[i][r]);
            }
            l++;
            r--;
        }
    }
    
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=4;
        while(n--){
            rotate90(mat);
            if(mat==target)
                return true;
        }
        return false;
    }
};