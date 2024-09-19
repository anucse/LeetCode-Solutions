class Solution {
public:
    bool closeStrings(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(m!=n)
            return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(char& x:s1){
            v1[x-'a']++;
        }
        for(char& x:s2){
            v2[x-'a']++;
        }

        for(int i=0;i<26;i++){
            if(v1[i]==0 && v2[i]!=0 || v1[i]!=0 && v2[i]==0  )
                return false;
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return v1==v2;
    }
};