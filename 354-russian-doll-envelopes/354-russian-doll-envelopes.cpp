class Solution {
public:
    static bool arrange(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),arrange);
        vector<int> lis;
        for(vector x:envelopes){
            int curr=x[1];
            int index=lower_bound(lis.begin(),lis.end(),curr)-lis.begin();
            if (index>=lis.size())
                lis.push_back(curr);
            else
                lis[index]=curr;
        }
        return lis.size();
    }
};