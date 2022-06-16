class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=INT_MIN;
        int area=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            area=min(height[left],height[right])*(right-left);
            max_area=max(max_area,area);
            if(height[left]<=height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};