class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int index=0;
        int mx=candies[0];
        int n=candies.size();
        vector<bool>ans (n);
        for(int i=0;i<n;i++){
            if(candies[i]>mx){
                mx=candies[i];
                index=i;
            }
        }

        for(int i=0;i<n;i++){
            if(mx-candies[i]>extra){
                ans[i]=false;
            }
            else{
                ans[i]=true;
            }
        }

        return ans;

    }
};