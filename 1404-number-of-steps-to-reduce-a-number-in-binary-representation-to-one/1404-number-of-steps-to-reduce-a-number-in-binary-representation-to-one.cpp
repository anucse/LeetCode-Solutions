class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        
        while(s!="1"){
            int n=s.size();
            if(s[n-1]=='1'){
                int j=n-1;
                while(j>=0 && s[j]=='1'){
                    s[j]='0';
                    j-=1;
                }
                if(j==-1)
                    s='1'+s;
                else
                    s[j]='1';
            }
            else{
                s.pop_back();
            }
            ans++;
        }
        return ans;
    }
};