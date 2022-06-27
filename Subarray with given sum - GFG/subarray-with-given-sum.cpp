// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long target)
    {
        long long sum=arr[0];
        vector<int> ans;
        int l=0;
        int r=1;
        while(r<=n){
            
            while(sum>target && l<r){
                sum-=arr[l];
                l++;
            }
            
            if(sum==target){
                ans.push_back(l+1);
                ans.push_back(r);
                break;
            }
            
            sum+=arr[r];
            r++;
        }
        if (ans.empty())
            return {-1};
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends