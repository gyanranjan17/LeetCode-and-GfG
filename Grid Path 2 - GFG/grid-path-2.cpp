//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long mod=1e9+7;
    int f(int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(m<0 || n<0) return 0;
        if(grid[m][n]==1) return dp[m][n]=0;
        if(m==0 && n==0) return dp[m][n]=1;
        
        if(dp[m][n]!=-1) return dp[m][n];
        int u=f(m-1,n,dp,grid);
        int l=f(m,n-1,dp,grid);
        return dp[m][n]=(l+u)%mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
         vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,grid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends