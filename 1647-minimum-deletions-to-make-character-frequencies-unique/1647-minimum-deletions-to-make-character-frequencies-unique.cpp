class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }
        
        int ans=0;
        
        unordered_set<int> st;
        
        for(auto x:m){
            while(st.find(x.second)!=st.end()){
                x.second--;
                ans++;
            }
            if(x.second>0)
                st.insert(x.second);
        }
        
        return ans;
    }
};