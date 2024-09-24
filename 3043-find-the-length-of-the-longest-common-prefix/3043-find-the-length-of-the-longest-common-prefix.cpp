class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;
        for(auto& x: arr1){
            string num=to_string(x);
            string prefix="";
            for(char& ch:num){
                prefix+=ch;
                mp[prefix]++;
            }
            
        }
        int ans=0;
        for(auto& x:arr2){
            string num=to_string(x);
            string prefix="";
            for(char& ch:num){
                prefix+=ch;
                if(mp.find(prefix)!=mp.end()){
                    int len=prefix.length();
                    ans=max(ans,len);
                }
            }
        }

        return ans;
    }
};