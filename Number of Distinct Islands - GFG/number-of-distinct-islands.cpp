//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j, vector<vector<int>> &vis, vector<vector<int>> &grid,int m,int n,int &p,int &q, vector<pair<int,int>> &v){
       
        v.push_back({i-p,j-q});
        vis[i][j]=1;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        for(int x=0;x<4;x++){
            int nrow=i+drow[x];
            int ncol=j+dcol[x];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
            dfs(nrow,ncol,vis,grid,m,n,p,q,v);
            }
        }
        // s.insert(v);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>> v;
                if(!vis[i][j] && grid[i][j]==1){
                dfs(i,j,vis,grid,m,n,i,j,v);
                s.insert(v);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends