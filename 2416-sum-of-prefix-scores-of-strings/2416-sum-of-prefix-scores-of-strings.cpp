class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> mp;
        for(auto& word:words){
            string prefix="";
            for(auto& ch:word){
                prefix+=ch;
                mp[prefix]++;
            }
        }

        for(auto& word:words){
            string prefix="";
            int count=0;
            for(auto& ch:word){
                prefix+=ch;
                count+=mp[prefix];
            }
            ans.push_back(count);
        }

        return ans;
    }
};