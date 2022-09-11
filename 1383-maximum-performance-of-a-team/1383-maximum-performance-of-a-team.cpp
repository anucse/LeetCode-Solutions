class Solution {
public:
    const long long int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v; //{efficiency,speed}
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.begin(),v.end(),greater());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long speedSum=0;
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                speedSum-=pq.top();
                pq.pop();
            }
            speedSum+=v[i].second;
            pq.push(v[i].second);
            long long performance=(speedSum*v[i].first);
            ans=max(ans,performance);
        }
        
        return ans%(long long int )mod;
    }
};















