class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_count=0;
        int max_appearing=0;
        
        vector<int> count(26,0);
        
        for(char c:tasks){
            count[c-'A']++;
            max_count=max(max_count,count[c-'A']);
        }
        
        for(int i=0;i<26;i++){
            if(max_count==count[i])
                max_appearing++;
        }
        
        return max((int)tasks.size(),((max_count-1)*(n+1)+max_appearing));
    }
};