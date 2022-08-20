class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        if(target<=startFuel)
            return 0;
        int n=stations.size();
        int ans=0;
        priority_queue<int> pq;
        int i=0;
        
        while(startFuel<target){
            while(i<n && startFuel>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            
            startFuel+=pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
        
    }
};