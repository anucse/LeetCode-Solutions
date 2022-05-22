class Solution {
public:
    //start from centre , extend to left and right
    int countSubstrings(string s) {
        int n=s.size();
        int i,left,right,ans=n;
        
        // for odd palindromes
        for(int i=1,left=0,right=2;i<n;i++,left=i-1,right=i+1){
            while(left>=0 && right<n && s[left]==s[right] ){
                left--;
                right++;
                ans++;
            }
            
            
        }
        
        // For even palindromes
        for(i=1,left=0,right=1;i<n;i++,left=i-1, right=i){
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                ans++;
            }
            
           
        }
        return ans;
    }
};