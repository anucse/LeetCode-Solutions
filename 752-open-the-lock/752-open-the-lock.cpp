class Solution {
public:
    int openLock(vector<string>& dead, string target) {
        
        unordered_set<string> visited;
        unordered_set<string> dead_set(dead.begin(),dead.end());
        int ans=0;
        
        string start="0000";
        
        if(dead_set.find(target)!=dead_set.end() || dead_set.find(start)!=dead_set.end())
            return -1;
        
        queue<string> q;
        q.push(start);
        visited.insert(start);
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string top=q.front();
                q.pop();
                
                if(target==top)
                    return ans;
                
                for(int j=0;j<4;j++){
                    char a = top[j];
                    
                    top[j]=(((a-'0')+1)%10)+'0';
                    
                    if(dead_set.find(top)==dead_set.end()&&visited.find(top)==visited.end()){
                        q.push(top);
                        visited.insert(top);
                    }
                    top[j]=(((a-'0')+9)%10)+'0';
                    if(dead_set.find(top)==dead_set.end()&&visited.find(top)==visited.end()){
                        q.push(top);
                        visited.insert(top);
                    }
                    top[j]=a;
                }
            }
            ans++;
        }
        return -1;
    }
};