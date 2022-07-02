class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
        long int maxHeight=0;
        long int maxWidth=0;
        
        horizontal.push_back(h);
        vertical.push_back(w);
        
        sort(horizontal.begin(),horizontal.end());
        sort(vertical.begin(),vertical.end());
        
        for(int i=0,prev=0;i<horizontal.size();++i){
            maxHeight=max(maxHeight,(long int)horizontal[i]-prev);
            prev=horizontal[i];
        }
        
        for(int i=0,prev=0;i<vertical.size();++i){
            maxWidth=max(maxWidth,(long int)vertical[i]-prev);
            prev=vertical[i];
        }
        
        return (maxHeight*maxWidth)%1000000007;
    }
};