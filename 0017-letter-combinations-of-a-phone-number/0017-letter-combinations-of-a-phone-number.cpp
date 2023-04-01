class Solution {
public:
    vector<string> ans;
    void solve(string digits,vector<string> m, string temp,int i){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        
        int digit=digits[i]-'0';
        for(int j=0;j<m[digit].size();j++){
            solve(digits,m,temp+m[digit][j],i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0)
            return {};
        vector<string> m(10);
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        string temp="";
        solve(digits,m,temp,0);
        
        return ans;
           
    }
};