class Solution {
public:
    vector<bool> dp;
    
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(),d.end());
        int n=s.size();
        dp.resize(n+1,false);
        
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(st.count(s.substr(i,j-i+1)) && dp[j+1]){
                    dp[i]=true;
                    break;
                }
            }
            
            
        }
        
        return dp[0];
    }
};