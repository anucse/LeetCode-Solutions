// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int n) {
        int index=0;
        int num=n;
        for(int i=0;i<32;i++){
            if((n & 1)==1){
                index=i;
            }
            n>>=1;
        }
        
        vector<int> ans(2);
        int newNum=(1<<(index+1))-1;
        ans[0]=abs(num-newNum);
        ans[1]=newNum;
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends