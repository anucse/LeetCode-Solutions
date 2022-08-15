class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> v=
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
            
        };
        
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            if(v[s[i]]<v[s[i+1]])
                ans-=v[s[i]];
            else
                ans+=v[s[i]];
        }
        
        return ans;
    }
};