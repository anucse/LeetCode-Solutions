class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        unordered_set<string> word_set(word.begin(),word.end());
        int ans=1;
        if(word_set.find(end)==word_set.end() )
            return 0;
        queue<string> q;
        q.push(begin);
        while(!q.empty()){
            ans++;
            int n=q.size();
            for(int i=0;i<n;i++){
                string top=q.front();
                q.pop();
                
                for(int j=0;j<top.size();j++){
                    string temp=top;
                    for(char k='a';k<='z';k++){
                        top[j]=k;
                        if(temp==top)
                            continue;
                        if(top==end)
                            return ans;
                        if(word_set.find(top)!=word_set.end()){
                            q.push(top);
                            word_set.erase(top);
                        }
                    }
                    top=temp;
                }
            }
            
        }
        return 0;
    }
};