class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        vector<int>visited(26,0), count(26,0);
        
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']--;
            
            if(visited[s[i]-'a'])
                continue;
            
            while(!st.empty() && st.top()>s[i] && count[st.top()-'a']!=0){
                visited[st.top()-'a']=0;
                st.pop();
            }
            
            st.push(s[i]);
            visited[s[i]-'a']=1;
        }
        
        s.clear();
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        
        return s;
    }
};