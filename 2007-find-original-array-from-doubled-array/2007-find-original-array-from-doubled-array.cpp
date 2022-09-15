class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        map<int,int> m;
        for(int x:changed)
            m[x]++;
        
        vector<int> ans;
        
        for(auto x:m){
            if(x.second!=0){
                if(x.first==0 && (x.second&1) || !m.count(x.first*2)||m[x.first*2]<x.second)
                    return {};
                
                while(x.second){
                    if(x.first==0){
                        ans.push_back(x.first);
                        x.second-=2;
                    }
                    else{
                        x.second--;
                        m[x.first*2]--;
                        ans.push_back(x.first);
                    }
                    
                }
                
                
            }
        }
        
        return ans;
    }
};