class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxleft=height[0],maxright=height[n-1];
        int e;
        int res=0;
        
        while(i<=j){
            if(height[i]>height[j]){
                e=height[j];
                if(e>maxright)
                    maxright=e;
                else{
                    res+=(maxright-e);
                }
                j--;
            }
            
            else if(height[i]<=height[j]){
                e=height[i];
                if(e>maxleft)
                    maxleft=e;
                else{
                    res+=(maxleft-e);
                }
                i++;
            }
        }
        return res;
    }
};