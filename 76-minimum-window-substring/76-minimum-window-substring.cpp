class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_hash;
        for(char c:t)
            t_hash[c]++;
        
        int count=0;
        int low=0;
        int perfect_low=0;
        
        int min_len=INT_MAX;
        
        for(int high=0;high<s.size();high++){
            if(t_hash[s[high]]>0)
                count++;
            t_hash[s[high]]--;
            
            if(count==t.size()){
                while(low<high && t_hash[s[low]]<0){
                    t_hash[s[low]]++;
                    low++;
                }
                
                if(min_len>=(high-low+1)){
                    min_len=high-low+1;
                    perfect_low=low;
                    
                }
                
                t_hash[s[low]]++;
                low++;
                count--;
            }
        }
        if(min_len==INT_MAX)
            return "";
        return s.substr(perfect_low,min_len);
    }
};