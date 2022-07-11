class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int x:arr)
            m[((x%k)+k)%k]++;
        
        for(int x:arr){
            int rem=((x%k)+k)%k;
            if(rem==0){
                if(rem==0){
                    if (m[rem]&1)
                        return false;
                }
            }
            else if(m[rem]!=m[k-rem]){
                
                return false;
            }
        }
        return true;
    }
};