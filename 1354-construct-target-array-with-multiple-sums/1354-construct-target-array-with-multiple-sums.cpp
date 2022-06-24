class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int ones=0;
        
        priority_queue<int> pq(target.begin(),target.end());
        
        long long sum=0;
        
        for(int x:target){
            sum+=x;
            if(x==1)
                ones++;
        }
        while(true){
            int top=pq.top();
            pq.pop();
            sum=sum-top;
            if(top==1 || sum==1)
                return true;
            if(sum==0 || top<sum || top%sum==0)
                return false;
            int newNum=top%sum;
            sum=sum+newNum;
            pq.push(newNum);
            
        }
        
    }
};