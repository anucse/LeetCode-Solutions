class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s=s1+" "+s2;
        unordered_map<string,int> m;
        string temp="";
        vector<string> ans;
        int n=s.size();
        for(int i=0;i<=n;i++){
            
            if(i==n || s[i]==' '){
                m[temp]++;
                temp="";
            }
            else{
                temp+=s[i];
            }
            
        }
        for(auto& x:m){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};