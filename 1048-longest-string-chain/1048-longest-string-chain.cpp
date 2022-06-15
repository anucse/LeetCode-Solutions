class Solution {
public:
    static bool increasing_len(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    bool isPredecessor(string &s1, string &s2){
        int n1=s1.size();
        int n2=s2.size();
        if(n1 !=n2-1){
            return false;
        }
        
        int i=0;
        int j=0;
        while(j<n2){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        if(i==n1 && j==n2)
            return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),increasing_len);
        int n=words.size();
        int max_len=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPredecessor(words[j],words[i]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            max_len=max(max_len,dp[i]);
        }
        return max_len;
    }
};