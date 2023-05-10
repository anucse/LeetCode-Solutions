class Solution {
public:
    // pair<int,int> -> <num,index>
    static bool comp(pair<int,int> a, pair<int,int> b){
        return a.first<b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end(),comp);
        int n=nums.size();
        int i=0;
        int j=n-1;
        
        while(i<j){
            int sum=v[i].first+v[j].first;
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            else{
                return {v[i].second,v[j].second};
            }
        }
        
        return {};
    }
};