class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        unordered_set<string> wordSet(word.begin(),word.end());
        if(wordSet.find(end)==wordSet.end())
            return 0;
        int ans=1;
        queue<string> q;
        q.push(begin);
        if(wordSet.find(begin)!=wordSet.end())
            wordSet.erase(begin);
        while(!q.empty()){
            ans++;
            int s=q.size();
            for(int i=0;i<s;i++){
                string top=q.front();
                q.pop();
                for(int j=0;j<top.size();j++){
                    string temp=top;
                    for(char k='a';k<='z';k++){
                        top[j]=k;
                        if(top==temp)
                            continue;
                        if(top==end)
                            return ans;
                        if(wordSet.find(top)!=wordSet.end()){
                            wordSet.erase(top);
                            q.push(top);
                        }
                    }
                    top=temp;
                }
            }
        }
        return 0;
    }
};