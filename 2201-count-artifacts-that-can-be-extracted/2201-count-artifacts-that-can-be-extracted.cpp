class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
        set<vector<int>> s(dig.begin(),dig.end());
        int ans=art.size();
        for(vector<int> arr:art){
            int flag=0;
            for(int i=arr[0];i<=arr[2];i++){
                for(int j=arr[1];j<=arr[3];j++){
                    if(s.find({i,j})==s.end()){
                        ans--;
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            
            
        }
        return ans;
    }
};