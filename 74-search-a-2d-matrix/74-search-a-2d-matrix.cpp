class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        int low=0;
        int high=r*c-1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            int element=matrix[mid/c][mid%c];
            
            if(element>target)
                high=mid-1;
            else if(element<target)
                low=mid+1;
            else
                return true;
        }
        
        return false;
    }
};