class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(),env.end(),comp);
        vector<int> lis;
        for(int i=0;i<n;i++){
            auto it=lower_bound(lis.begin(), lis.end(),env[i][1]);
            if(it!=lis.end()){
                *it=env[i][1];
            }
            else
            lis.push_back(env[i][1]);
        }

        return lis.size();
    }

};