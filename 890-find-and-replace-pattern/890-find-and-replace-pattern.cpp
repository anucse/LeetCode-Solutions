class Solution {
public:
    bool solve(string w1,string w2){
        unordered_map<char,int> w1Tow2,w2Tow1;
        
        for(int i=0;i<w1.size();i++){
            if((w1Tow2.count(w1[i]) && w1Tow2[w1[i]]!=w2[i]) || 
              w2Tow1.count(w2[i]) && w2Tow1[w2[i]]!=w1[i])
                return false;
            
            else {
                w1Tow2[w1[i]]=w2[i];
                w2Tow1[w2[i]]=w1[i];
            }
        }
        
        return true;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for(string w:words){
            if(solve(w,pattern))
                ans.push_back(w);
        }
        
        return ans;
    }
};