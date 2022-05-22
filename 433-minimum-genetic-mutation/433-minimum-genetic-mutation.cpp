class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s(bank.begin(),bank.end());
        queue<string> q;
        if(s.find(end)==s.end())
            return -1;
        
        int ans=0;
        
        vector<char> c={'A','T','G','C'};
        
        q.push(start);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string top=q.front();
                q.pop();
                
                if(top==end)
                    return ans;
                
                s.erase(top);
                
                for(int j=0;j<8;j++){
                    char a=top[j];
                    for(int k=0;k<4;k++){
                        top[j]=c[k];
                        if(s.find(top)!=s.end()){
                            q.push(top);
                        }
                    }
                    top[j]=a;
                }
            }
            ans++;
        }
        return -1;
    }
    
};