class Solution {
public:
    int solve(vector<int> &hist){
        int n=hist.size();
        int area=0;
        stack<int> s;
        
        for(int i=0;i<n;i++){
            while(!s.empty() && hist[s.top()]>=hist[i]){
                int top=s.top();
                s.pop();
                
                int start;
                
                if(s.empty())
                    start=-1;
                else
                    start=s.top();
                
                int curr_area=hist[top]*(i-start-1);
                area=max(area,curr_area);
                
            }
            s.push(i);
        }
        
        while(!s.empty()){
            int top=s.top();
            s.pop();
                
            int start;
                
            if(s.empty())
                start=-1;
            else
                start=s.top();
                
            int curr_area=hist[top]*(n-start-1);
            area=max(area,curr_area);
                
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int ans;
        vector<int> hist(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1'){
                    hist[j]+=1;
                }
                else{
                    hist[j]=0;
                }
            }
            ans=max(ans,solve(hist));
        }
        return ans;
    }
};