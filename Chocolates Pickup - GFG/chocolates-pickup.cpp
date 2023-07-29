//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int f(int i,int a,int b,vector<vector<int>>& grid,int n,int m, vector<vector<vector<int>>> &dp){
        if(a>=m || a<0 || b<0 || b>=m) return 0;
        if(i==n-1){ 
            if(a!=b)
            return grid[i][a]+grid[i][b];
            else return grid[i][a];
        }
        if(dp[i][a][b]!=-1) return dp[i][a][b];
        int ans=0;
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
                if(a!=b)
                ans=max(ans,grid[i][a]+grid[i][b]+f(i+1,a+k,b+l,grid,n,m,dp));
                else ans=max(ans,grid[i][a]+f(i+1,a+k,b+l,grid,n,m,dp));
            }
        }
        return dp[i][a][b]=ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,n,m,dp);
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends