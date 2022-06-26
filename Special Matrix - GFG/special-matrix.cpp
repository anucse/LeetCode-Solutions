// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked){
	    
	      
	    vector<vector<int>> grid(n,vector<int>(m,0));
	    int mod=1000000007;
	    
	    for(vector<int> x:blocked){
	        grid[x[0]-1][x[1]-1]=-1;
	    }
	    
	    if(grid[0][0]==-1)
	        return 0;
	    
	    for(int i=0;i<n;i++){
	        if(grid[i][0]==0){
	            grid[i][0]=1;
	        }
	        else
	            break;
	    }
	    
	    for(int i=1;i<m;i++){
	        if(grid[0][i]==0)
	            grid[0][i]=1;
	        else 
	            break;
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=1;j<m;j++){
	            
	            if(grid[i][j]==-1)
	                continue;
	                
	            if(grid[i-1][j]>0){
	                grid[i][j]=grid[i][j]+grid[i-1][j]; // from up
	            }
	            
	            if(grid[i][j-1]>0){
	                grid[i][j]=grid[i][j]+grid[i][j-1]; // from left
	            }
	        }
	    }
	    
	    if(grid[n-1][m-1]>0)
	        return grid[n-1][m-1]%mod;
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends