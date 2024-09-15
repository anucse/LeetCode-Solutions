class Solution {
public:
    bool binarySearch(vector<int>& nums,int key,int s, int e){
        if (s>e)
            return false;
        int mid=s+(e-s)/2;
        if(nums[mid]==key)
            return true;
        if(key<nums[mid])
            return binarySearch(nums,key,s,mid-1);
        else
            return binarySearch(nums,key,mid+1,e);
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> temp;
        for(auto& x:nums1){
            if(!binarySearch(nums2,x,0,nums1.size()-1)){
                temp.push_back(x);
            }
        }
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        ans.push_back(temp);
        temp.clear();

        for(auto& x:nums2){
            if(!binarySearch(nums1,x,0,nums2.size()-1)){
                temp.push_back(x);
            }
        }
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        ans.push_back(temp);
        temp.clear();


        return ans;

    }
};