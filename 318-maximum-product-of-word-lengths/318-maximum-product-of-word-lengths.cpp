class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n=words.size();
        int ans=0;
        vector<int> mask(n);
        
        for(int i=0;i<n;++i){
            for(char x:words[i]){
                mask[i]=mask[i] | (1<<(x-'a'));
            }
            
            for(int j=0;j<i;++j){
                if(mask[i] & mask[j])
                    continue;
                int len = words[i].size() * words[j].size();
                ans=max(ans,len);
            }
        }
        return ans;
    }
};