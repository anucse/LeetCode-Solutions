class Solution {
public:
    int minPartitions(string s) {
        int d;
        int maxDigit=0;
        for(int i=0;i<s.size();i++){
            int d=s[i]-'0';
            maxDigit=max(maxDigit,d);
        }
        
        return maxDigit;
    }
};