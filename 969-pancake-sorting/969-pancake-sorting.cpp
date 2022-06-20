class Solution {
public:
    int findIndex(vector<int>& arr,int x){
        int index;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x)
                index=i;
        }
        return index;
    }
    
    void flip(vector<int>& A, int ind) {
        int s = 0, e = ind;
        while(s<e) {
            swap(A[s++], A[e--]);
        }
    }
    
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int curr=arr.size()-1;
        while(curr>=1){
            if(arr[curr]==curr+1)
                curr--;
            
            int pos=findIndex(arr,curr+1);
            flip(arr,pos);
            res.push_back(pos+1);
            flip(arr,curr);
            res.push_back(curr+1);
            curr--;  
        }
        return  res;
    }
};