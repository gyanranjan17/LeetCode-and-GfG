//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>>& grid,int m,int n){
        vis[i][j]=1;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        for(int x=0;x<4;x++){
            int nrow=i+drow[x];
            int ncol=j+dcol[x];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            dfs(nrow,ncol,vis,grid,m,n);
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j])
                dfs(0,j,vis,grid,m,n);
            if(grid[n-1][j] && !vis[n-1][j])
                dfs(n-1,j,vis,grid,m,n);
        }
        for(int i=1;i<=n-2;i++){
            if(grid[i][0]==1 && !vis[i][0])
                dfs(i,0,vis,grid,m,n);
            if(grid[i][m-1]==1 && !vis[i][m-1])
                dfs(i,m-1,vis,grid,m,n);
        }
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++)
            if(!vis[i][j] && grid[i][j]==1)
            count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends