class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> curr(n,0);
        //vector<int> prev(n,0);
        
        int ans=0; 
        
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    if(i==0||j==0){
                        curr[j]=1;
                    }
                    else{
                        curr[j]=1+curr[j-1];
                    }
                    ans=max(ans,curr[j]);
                    
                }
                else curr[j]=0;
                
                
            }
        }
        return ans;
        
    }
};