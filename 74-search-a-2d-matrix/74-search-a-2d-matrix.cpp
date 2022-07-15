class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int l=0;
        int h=r*c-1;
        while(l<=h){
            int m=l+(h-l)/2;
            int midElement=matrix[m/c][m%c];
            if(midElement==target)
                return true;
            else if(midElement>target)
                h=m-1;
                
            else 
                l=m+1;
        }
        
        return false;
    }
};