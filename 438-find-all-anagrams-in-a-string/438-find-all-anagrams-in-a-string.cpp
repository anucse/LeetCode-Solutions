class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss=s.size();
        int ps=p.size();
        if(ss<ps)
            return {};
        vector<int> ans;
        int left=0;
        int right=0;
        vector<int> s_hash(26,0);
        vector<int> p_hash(26,0);
        for(int i=0;i<ps;i++){
            p_hash[p[i]-'a']++;
            s_hash[s[i]-'a']++;
        }
        right=ps-1;
        while(right<ss){
            if(s_hash==p_hash)
                ans.push_back(left);
            right++;
            if(right!=ss){
                s_hash[s[right]-'a']++;
            }
            s_hash[s[left]-'a']--;
            left++;
        }
        return ans;
    }
};