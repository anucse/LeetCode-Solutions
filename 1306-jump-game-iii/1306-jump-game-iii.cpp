class Solution {
public:
    vector<bool> visited;
    bool dfs(vector<int> &arr , int index){
        if(index<0|| index>=arr.size()||visited[index])
            return false;
        if(arr[index]==0)
            return true;
        else
            visited[index]=true;
        return (dfs(arr,index+arr[index])||dfs(arr,index-arr[index]));
    }
    bool canReach(vector<int>& arr, int start) {
        visited=vector<bool>(arr.size(),false);
        return dfs(arr,start);
    }
};