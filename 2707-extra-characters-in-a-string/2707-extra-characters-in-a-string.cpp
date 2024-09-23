class Solution {
public:
    unordered_map<string, int> m;
    unordered_map<int, int> dp;

    int solve(string s,int index){
        if(index>=s.size()){
            return 0;
        }
        if(dp.find(index)!=dp.end()){
            return dp[index];
        }
        int extra=INT_MAX;
        string temp="";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(m.find(temp)!=m.end()){
                extra=min(extra,solve(s,i+1));
            }
        }
        extra=min(extra,1+solve(s,index+1));

        dp[index]=extra;

        return dp[index];
    }
    int minExtraChar(string s, vector<string>& dictionary) {

        int n=s.size();
        
        dp[n]=0;
        
        for(auto& x: dictionary){
            m[x]++;
        }

        return solve(s,0);
    }
};