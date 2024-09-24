class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> v(n,0);//0->locked, 1->unlocked
        v[0]=1;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
           
            for(auto& x:rooms[top]){
                if(!v[x]){
                    q.push(x);
                    v[x]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(v[i]==0)
                return false;
        }

        return true;
    }
};