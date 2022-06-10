class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxHeap;
        vector<vector<int>> ans;
        
        for(vector p:points){
            int x=p[0];
            int y=p[1];
            
            maxHeap.push({(x*x+y*y),x,y});
            if(maxHeap.size()>k)
                maxHeap.pop();
        }
        
        for(int i=0;i<k;i++){
            vector<int> top=maxHeap.top();
            maxHeap.pop();
            ans.push_back({top[1],top[2]});
        }
        
        return ans;
    }
};