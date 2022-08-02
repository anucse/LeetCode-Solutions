class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int l=matrix[0][0];
        int h=matrix[n-1][n-1]+1;
        
        int count ;
        int j;
        
        while(l<h){
            int mid=l+(h-l)/2;
            count=0;
            j=n-1;
            for(int i=0;i<n;i++){
                while(j>=0 && matrix[i][j]>mid)
                    j--;
                count+=(j+1);
            }
            
            if(count<k)
                l=mid+1;
            else
                h=mid;
        }
        
        return l;
    }
};