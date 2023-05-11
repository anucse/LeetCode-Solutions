//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i ==0 )
                return false;
            
        }
        
        return true;
    }
    
    vector<int> getPrimes(int n) {
        if(n<4){
            return {-1,-1};
        }
        
        if(n%2 !=0 ){
            if(!isPrime(n-2)){
                return {-1,-1};
            }
            else{
                return {2,n-2};
            }
        }
        else{
            unordered_set<int> st;
            for(int i=2;i<=n;i++){
                if(isPrime(i) && isPrime(n-i)){
                    return {i,n-i};
                }
            }
        }
        
        return {-1,-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<int> ptr = ob.getPrimes(N);
        cout << ptr[0]<<" "<<ptr[1] << endl;
    }
    return 0;
}
// } Driver Code Ends