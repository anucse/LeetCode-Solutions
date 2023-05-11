//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long fact(int n){
        if(n==0 || n==1)
            return 1;
        else
            return fact(n-1)*n;
    }
    
    int right(string s, int i){
        int a=0;
        for(int j=i+1;j<s.size();j++){
            if(s[i]>s[j]){
                a++;
            }
        }
        
        return a;
    }
    long long findRank(string str) {
        int n=str.size();
        long long rank=1;
        for(int i=0;i<n;i++){
            rank=rank+ right(str,i)*fact(n-i-1);
        }
        
        return rank;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends