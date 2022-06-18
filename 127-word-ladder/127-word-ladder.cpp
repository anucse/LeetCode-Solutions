class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(end)==wordSet.end() )
            return 0;
        queue<string> q;
        q.push(begin);
        if(wordSet.find(end)!=wordSet.end())
            wordSet.erase(begin);
        
        int ans=1;
        
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
                        if(temp==top)
                            continue;
                        if(top==end)
                            return ans;
                        if(wordSet.find(top)!=wordSet.end()){
                            q.push(top);
                            wordSet.erase(top);
                        }
                    }
                    top=temp;
                }
            }
        }
        return 0;
    }
};