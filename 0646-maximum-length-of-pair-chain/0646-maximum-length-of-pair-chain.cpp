class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return (a[1]<b[1]);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n =pairs.size();
        int prev=0;
        int res=1;
        sort(pairs.begin(),pairs.end(),comp);
        for(int i=1;i<n;i++){
            if(pairs[prev][1]<pairs[i][0]){
                prev=i;
                res++;
            }
        }

        return res;
    }
};