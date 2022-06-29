class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int n=people.size();
        
        vector<vector<int>> ans(n);
        
        sort(people.begin(),people.end(),compare);
        for(vector<int> &x:people){
            int index=x[1];
            int j;
            int c=0;
            for(j=0;j<n;j++){
                
                if(ans[j].empty()){
                    c++;
                }
                
                if(c-1==index){
                    ans[j]=x;
                    break;
                }
            }
            
        }
        return ans;
    }
};