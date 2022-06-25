// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubarrayXOR(int arr[], int n)
    {
        int index=0;
        int ans=0;
        for(int i=31;i>=0;i--){
            int maxIndex=index;
            int maxElement=INT_MIN;
            for(int j=index;j<n;j++){
                if((arr[j]&(1<<i))!=0 && arr[j]>=maxElement){
                    maxElement=arr[j];
                    maxIndex=j;
                }
            }
            if(maxElement==INT_MIN)
                continue;
            
            swap(arr[index],arr[maxIndex]);
            
            maxIndex=index;
            
            for(int j=0;j<n;j++){
                if(j!=maxIndex && ((arr[j] & (1<<i))!=0))
                    arr[j]=arr[maxIndex]^arr[j];
            }
            
            index++;
        }
        
        for(int i=0;i<n;i++){
            ans=ans^arr[i];
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}  // } Driver Code Ends