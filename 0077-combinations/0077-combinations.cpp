class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(int n,int k,int i){
        
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(i>n)
            return;
        
        temp.push_back(i);
        solve(n,k-1,i+1);
        temp.pop_back();
        solve(n,k,i+1);
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,1);
        return ans;
    }
};