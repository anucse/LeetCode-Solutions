class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(n==1 && trust.size()==0)
            return 1;
        vector<int> in(n+1,0); // indegree -> trusted by
        vector<int> out(n+1,0); // outdegree -> trusts
        
        for(vector<int> x:trust){
            in[x[1]]++;
            out[x[0]]++;
        }
        
        for(int i=0;i<=n;i++){
            if(in[i]==n-1 && out[i]==0)
                return i;
        }
        
        return -1;
    }
};