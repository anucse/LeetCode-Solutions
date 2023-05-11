//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int a, int b, int c){
        if(a<b){
            if(a<c){
                if(b<c)
                    return b;
                else
                    return c;
            }
            else{
                return a;
            }
        }
        else{
            if(b<c){
                if(a<c)return a;
                else return c;
            }
            else{
                return b;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
// } Driver Code Ends