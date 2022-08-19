class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int minProd=1;
        int maxProd=1;
        
        for(int& x:nums){
            if(x<0)
                swap(minProd,maxProd);
            minProd=min(minProd*x,x);
            maxProd=max(maxProd*x,x);
            ans=max(ans,maxProd);
        }
        
        return ans;
    }
};