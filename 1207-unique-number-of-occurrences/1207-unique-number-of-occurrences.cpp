class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int& x:nums){
            m[x]++;
        }
        unordered_set<int> st;
        for(auto& x:m){
            if(st.find(x.second)!=st.end()){
                return false;
            }
            st.insert(x.second);
        }

        return true;
    }
};