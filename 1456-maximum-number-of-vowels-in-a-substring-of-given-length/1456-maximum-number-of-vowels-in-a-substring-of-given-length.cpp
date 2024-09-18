class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int x=0;
        int ans=INT_MIN;
        vector<char> vowels={'a','e','i','o','u'};
        for(int i=0;i<k;i++){
            if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end()){
                x++;
            }
        }
        int l=0;
        int r=k;
        while(r<n){
            if(find(vowels.begin(),vowels.end(),s[l])!=vowels.end()){
                x--;
            }
            if(find(vowels.begin(),vowels.end(),s[r])!=vowels.end()){
                x++;
            }
            l++;
            r++;
            ans=max(ans,x);
            
        }
        return ans;
    }
};