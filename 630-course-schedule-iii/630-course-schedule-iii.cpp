class Solution {
public:
    static bool compare(vector<int> &v1,vector<int> &v2 ){
        return (v1[1]<v2[1]);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),compare);
        
        priority_queue<int> pq;
        int nextStart=0;
        
        for(vector<int> course:courses){
            int duration=course[0];
            int deadline=course[1];
            
            if(nextStart+duration<=deadline){
                nextStart+=duration;
                pq.push(duration);
            }
            
            else if(!pq.empty() && duration<pq.top()){
                nextStart-=pq.top();
                nextStart+=duration;
                pq.pop();
                pq.push(duration);
            }
        }
        
        return pq.size();
    }
};