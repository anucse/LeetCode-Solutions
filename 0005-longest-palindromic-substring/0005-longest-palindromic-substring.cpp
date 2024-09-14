class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        int sum=0;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<=n && s[l]==s[r]){
                if(r-l+1>sum){
                    sum=r-l+1;
                    ans=s.substr(l,sum);
                    
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<=n && s[l]==s[r]){
                if(r-l+1>sum){
                    sum=r-l+1;
                    ans=s.substr(l,sum);
                    
                }
                l--;
                r++;
            }

            

        }

        return ans;
    }
};