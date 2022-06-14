class Solution {
public:
    vector<vector<int>> dp;
    int solve(string w1, string w2,int i,int j){
        if(i==w1.size() && j==w2.size())
            return 0;
        if(i==w1.size() || j==w2.size())
            return max(w1.size()-i,w2.size()-j);
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        if(w1[i]==w2[j])
            return solve(w1,w2,i+1,j+1);
        return dp[i][j]=1+min(solve(w1,w2,i+1,j),solve(w1,w2,i,j+1));
    }
    int minDistance(string word1, string word2) {
        dp=vector<vector<int>>(word1.size()+1,vector<int> (word2.size()+1,INT_MAX));
        return solve (word1,word2,0,0);
    }
};