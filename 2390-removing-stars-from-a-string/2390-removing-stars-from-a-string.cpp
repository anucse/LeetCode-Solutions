class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char& x:s){
            if(x=='*'){
                if(ans.size()>0){
                    ans.pop_back();
                }
                
            }
            else{
                ans.push_back(x);
            }
        }

        return ans;
    }
};