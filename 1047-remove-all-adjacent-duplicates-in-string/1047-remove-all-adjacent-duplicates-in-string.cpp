class Solution {
public:
    string removeDuplicates(string s) {
        
        int i=0;
        stack<char> st;
        st.push(s[0]);
        i++;
        int n=s.size();
        
        while(i<n){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            
            else{
                st.push(s[i]);
            }
            
            i++;
        }
        
        s="";
        
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        
        reverse(s.begin(),s.end());
        
        return s;
    }
};