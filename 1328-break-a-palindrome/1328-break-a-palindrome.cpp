class Solution {
public:
    bool strequals(string a, string b) {
        int i = 0;
        while(i < a.size()) {
            if(a[i] != b[i]) {
                return false;
            }
            i += 1;
        }        
        return true;
    }
    string breakPalindrome(string palindrome) {
        if(palindrome.size() <= 1) return "";
        // if all a then replacet last a by b
        if(strequals(palindrome, string(palindrome.length(), 'a'))) {
            palindrome[palindrome.length() - 1] = 'b';
        } 
        // else replace first non a with a
        else {
            string cpalindrome = palindrome;
            int idx = 0;
            for(int i=0; i<cpalindrome.size(); ++i) {
                if(cpalindrome[i] != 'a') {
                    cpalindrome[i] = 'a';
                    idx = i;
                    break;
                }
            }         
			// for strings like "aba" ... expected solution is "abb"
          if(strequals(cpalindrome, string(cpalindrome.length(), 'a'))) {
            palindrome[palindrome.length() - 1] = 'b';
          } else {
            palindrome[idx] = 'a';
          }
        }
        return palindrome;
    }
};