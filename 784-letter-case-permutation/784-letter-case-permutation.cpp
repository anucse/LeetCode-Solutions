class Solution {
public:
    vector<string> ans;
    string temp="";
    void solve(string s,string temp, int n, int i){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        if(isdigit(s[i])){
            temp+=s[i];
            solve(s,temp,n,i+1);
        }
        else {
            string temp1=temp;
            temp1+=tolower(s[i]);
            solve(s,temp1,n,i+1);
            
            string temp2=temp;
            temp2+=toupper(s[i]);
            solve(s,temp2,n,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,"",s.size(),0);
        return ans;
    }
};