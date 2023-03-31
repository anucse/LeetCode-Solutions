class Solution {
public:
    vector<string> ans;
    
    void solve(int n,int open,int close,string temp){
        
        if(!open && !close){
            ans.push_back(temp);
            return;
        }
        
        if(open>0){
            temp.push_back('(');
            solve(n,open-1,close,temp);
            temp.pop_back();
        }
        
        if(close>open){
            temp.push_back(')');
            solve(n,open,close-1,temp);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        int open=n;
        int close=n;
        
        string temp="";
        
        solve(n,open,close,temp);
        return ans;
    }
};