class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        vector<int> v(26,0);
        int r=ransom.size();
        int m=magazine.size();
        for(int i=0;i<m;i++){
            v[magazine[i]-'a']++;
        }
        for(int i=0;i<r;i++){
            v[ransom[i]-'a']--;
        }
        
        for(int x:v){
            if(x<0)
                return false;
        }
        return true;
    }
};