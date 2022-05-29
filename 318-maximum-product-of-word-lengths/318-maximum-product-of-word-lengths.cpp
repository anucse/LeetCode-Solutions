class Solution {
public:
    
    bool common(bitset<26> &w1,bitset<26> &w2){
        for(int i=0;i<26;i++){
            if(w1[i] && w2[i])
                return true;
        }
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        vector<bitset<26>> chars(n);
        for(int i=0;i<n;i++){
            for(char x:words[i]){
                chars[i][x-'a']=1;
            }
            for(int j=0;j<i;j++){
                if(!common(chars[i],chars[j])){
                    int len = words[i].size() * words[j].size();
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};