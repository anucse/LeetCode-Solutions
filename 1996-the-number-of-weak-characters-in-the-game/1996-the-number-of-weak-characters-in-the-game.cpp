class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return (a[0]>b[0]);
        else 
            return (a[1]<b[1]);
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(),properties.end(),compare);
        
        int currMax=INT_MIN;
        int ans=0;
        
        for(auto x:properties){
            if(x[1]>currMax)
                currMax=x[1];
            else if(x[1]<currMax)
                ans++;
        }
        
        return ans;
    }
};