class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1)
            return false;
        
        unordered_map<int,unordered_set<int>> m;
        
        for(int x:stones){
            m[x]={} ;
        }
        m[0].insert(1);
        
        for(int i=0;i<n;i++){
            for(int jump:m[stones[i]]){
                int pos = stones[i]+jump;
                if(pos == stones[n-1])
                    return true;
                if(m.find(pos)==m.end())
                    continue;
                m[pos].insert(jump);
                m[pos].insert(jump+1);
                if(jump-1>0)
                    m[pos].insert(jump-1);
            }
        }
        return false;
        
    }
};