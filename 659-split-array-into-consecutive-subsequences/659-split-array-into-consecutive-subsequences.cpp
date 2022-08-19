class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        map<int,int> m,m1;
        for(int x:nums){
            m[x]++;
        }
        
        for(int x:nums){
            if(m[x]==0)
                continue;
            m[x]--;
            if(m1[x-1]>0){
                m1[x-1]--;
                m1[x]++;
            }
            else if(m[x+1]>0 && m[x+2]>0){
                m[x+1]--;
                m[x+2]--;
                m1[x+2]++;
            }
            
            else 
                return false;
        }
        
        return true;
    }
};