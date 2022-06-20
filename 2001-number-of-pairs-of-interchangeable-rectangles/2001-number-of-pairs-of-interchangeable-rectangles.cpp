class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
       unordered_map<double,int> m;
        
        for(vector<int> x:r){
            double ratio=x[0]/(double)x[1];
            m[ratio]++;
        }
        
        long long ans=0;
        
        for(auto x: m){
            if(x.second<=1)
                continue;
            long long n=x.second;
            ans+=((n*(n-1))/2);
        }
        return ans;
    }
};