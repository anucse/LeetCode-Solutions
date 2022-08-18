class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        
        
        for(int x:arr){
            m[x]++;
        }
        
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        
        int n=arr.size();
        int target=n/2;
        int ans=0;
        
        while(!pq.empty() && n>target){
            auto top=pq.top();
            pq.pop();
            n-=top.first;
            ans++;
        }
        
        return ans;
    }
};