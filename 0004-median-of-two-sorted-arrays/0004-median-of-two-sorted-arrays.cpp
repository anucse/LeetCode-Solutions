class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int k=0;
        vector<int> nums3(nums1.size()+nums2.size());

        for(k=0;k<nums1.size()+nums2.size();k++){

            if (i<nums1.size() & j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    nums3[k]=nums1[i];
                    i++;
                } 
                else {
                    nums3[k]=nums2[j];
                    j++;
                }
                
            }
            else if (i<nums1.size()){
                nums3[k]=nums1[i];
                i++;
            }
            else {
                nums3[k]=nums2[j];
                j++;
            }

            
        }
        int n=nums3.size()-1;

        if (n % 2 ==0)
            return (nums3[n/2]);
         
        return (nums3[n/2]+nums3[n/2+1])/2.00;
    }
};