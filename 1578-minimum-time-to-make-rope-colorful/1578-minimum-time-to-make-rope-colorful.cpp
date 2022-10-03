class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int totalTime=0;
        int gain=0;
        int maxTime=INT_MIN;
        
        for(int x:neededTime){
            totalTime+=x;
        }
        
        int n=neededTime.size();
        int i=0;
        
        while(i<n){
            char curr=colors[i];
            maxTime=neededTime[i];
            
            int j=i;
            
            while(j<n && colors[i]==colors[j]){
                maxTime=max(maxTime,neededTime[j]);
                j++;
            }
            
            i=j;
            gain+=maxTime;
        }
        
        return totalTime-gain;
    }
};