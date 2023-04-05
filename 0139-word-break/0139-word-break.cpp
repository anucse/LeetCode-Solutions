class Solution {
public:
    vector<int> dp;
    bool solve(string s,unordered_set<string> &st,int i){
        
        if(i==s.size())
            return true;
        
        if(dp[i]!=-1)
            return dp[i];
        
        for(int j=i;j<s.size();j++){
            if(st.count(s.substr(i,j-i+1)) && solve(s,st,j+1)){
                return dp[i]=1;
            }
        }
        
        return dp[i]=0;
        
    }
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(),d.end());
        int n=s.size();
        dp.resize(n+1,-1);
        return solve(s,st,0);
    }
};