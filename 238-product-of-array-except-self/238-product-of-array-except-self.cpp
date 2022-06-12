class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>> product(n);
        
        product[0].first=1;
        product[n-1].second=1;
        
        for(int i=1;i<n;i++){
            product[i].first=product[i-1].first*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            product[i].second=product[i+1].second*nums[i+1];
        }
        
        for(int i=0;i<n;i++){
            nums[i]=product[i].first*product[i].second;
        }
        return nums;
    }
};