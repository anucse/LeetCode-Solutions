// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
    
    long long mini=INT_MAX;
    long long maxi=INT_MAX;
    int i;
    if(n%2==0){
        if(a[0]>a[1]){
            mini=a[1];
            maxi=a[0];
        }
        else{
            mini=a[0];
            maxi=a[1];
        }
        i=2;
    }
    
    else{
        if(a[0]>a[1]){
            mini=a[1];
            maxi=a[0];
        }
        else{
            mini=a[0];
            maxi=a[1];
        }
        i=1;
    }
    
    while(i<n-1){
        if(a[i]>a[i+1]){
            mini=min(a[i+1],mini);
            maxi=max(a[i],maxi);
        }
        else{
            maxi=max(a[i+1],maxi);
            mini=min(a[i],mini);
        }
        i+=2;
    }
    return {mini,maxi};
}