class Solution {
public:
    vector<string> readBinaryWatch(int t) {
        vector<string> ans;
        for (int i=0; i<=11; i++){
            for (int j= 0; j<= 59; j++){
                if (__builtin_popcount(i)+ __builtin_popcount(j)== t){
                    string s= to_string(i)+':';
                    if(j<=9) s+='0';
                    s+=to_string(j);
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};