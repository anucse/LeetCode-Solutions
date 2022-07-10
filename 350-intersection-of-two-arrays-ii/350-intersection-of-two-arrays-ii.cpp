class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int x:nums1){
            m[x]++;
        }
        
        for(int x: nums2){
            if(m.find(x)!=m.end()){
                ans.push_back(x);
                if(m[x]==1){
                    
                    m.erase(x);
                }
                else{
                    m[x]--;
                }
            }
        }
        return ans;
    }
};