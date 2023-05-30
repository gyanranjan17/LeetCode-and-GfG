//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int f(int r,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
    //     int m=grid.size(),n=grid[0].size();
    //     if(c1 <0 || c1>=n || c2<0 || c2>=n) return 0;
    //     if(r==m-1){
    //         if(c1==c2) return dp[r][c1][c2]= grid[r][c1];
    //         else
    //         return 
    //             dp[r][c1][c2] =grid[r][c1] + grid[r][c2];
            
    //     }
    //     if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
    //     int maxi=0;
    //     for(int i=-1;i<=1;i++){
    //         for(int j=-1;j<=1;j++){
    //             if(c1==c2)
    //                 maxi=max(maxi,grid[r][c1] + f(r+1,c1+i,c2+j,grid,dp));
    //             else maxi=max(maxi,grid[r][c1] +grid[r][c2] + f(r+1,c1+i,c2+j,grid,dp));
    //         }
    //     }
    //     return dp[r][c1][c2]=maxi;
        
    // }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int k=m-1;k>=0;k--){
    
                    if(i==n-1){
                        if(j==k) dp[i][j][k]= grid[i][j];
                        else
                        dp[i][j][k] =grid[i][j] + grid[i][k];
                    }
                    
                    else{
                        
                        for(int a=-1;a<=1;a++){
                            for(int b=-1;b<=1;b++){
                                if(j+a>=0 && j+a<m && k+b>=0 && k+b<m){
                                    if(j==k)
                                    dp[i][j][k]=max(dp[i][j][k],grid[i][j] + dp[i+1][j+a][k+b]);
                                    else
                                    dp[i][j][k]=max(dp[i][j][k],grid[i][j] +grid[i][k] + dp[i+1][j+a][k+b]);
                                }
                            }
                        }
                    }
                    // dp[i][j][k]=maxi;
                    
                }
            }
        }
        return dp[0][0][m-1];
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