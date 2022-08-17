class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> ans;
        vector<string> alpha ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(string s:words){
            string temp="";
            for(char c:s){
                temp+=alpha[c-97];
            }
            ans.insert(temp);
        }
        
        return ans.size();
    }
};