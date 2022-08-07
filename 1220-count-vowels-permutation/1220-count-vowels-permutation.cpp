class Solution {
public:
    
    int MOD=1e9+7;
    
    const unordered_map<char, vector<char>> m { {'s', {'a', 'e', 'i', 'o', 'u'} }, 
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
    
    int solve(char prev,int i,int n, unordered_map<char,vector<int>> &dp){
        
        if(i==n)
            return 1;
        if(dp[prev][i]!=-1)
            return dp[prev][i];
        
        int ans=0;
        
        for(char c:m.at(prev)){
            ans=(ans+solve(c,i+1,n,dp))%MOD;
        }
        
        return dp[prev][i]=ans;
    }
    int countVowelPermutation(int n) {
        unordered_map<char,vector<int>> dp;
        dp['s']=dp['a']=dp['e']=dp['i']=dp['o']=dp['u']=vector<int>(n+1,-1);
        return solve('s',0,n,dp);
    }
};