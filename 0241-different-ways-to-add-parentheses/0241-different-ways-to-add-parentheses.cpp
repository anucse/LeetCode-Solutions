class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            char oper=s[i];
            if(oper=='+'||oper=='-'||oper=='*'){
                vector<int> s1=diffWaysToCompute(s.substr(0,i));
                vector<int> s2=diffWaysToCompute(s.substr(i+1));
                for(int a:s1){
                    for(int b:s2){
                        if(oper=='+') 
                            ans.push_back(a+b);
                        else if(oper=='-') 
                            ans.push_back(a-b);
                        else if(oper=='*') 
                            ans.push_back(a*b);
                    }
                }
            }
            
        }
        if(ans.empty())
            ans.push_back(stoi(s));
        return ans;
    }
};