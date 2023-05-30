//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<int>> front(m,vector<int>(m,-1));
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> cur(m,vector<int>(m,0));
            for(int j=m-1;j>=0;j--){
                for(int k=m-1;k>=0;k--){
    
                    if(i==n-1){
                        if(j==k) cur[j][k]= grid[i][j];
                        else
                        cur[j][k] =grid[i][j] + grid[i][k];
                    }
                    
                    else{
                        
                        for(int a=-1;a<=1;a++){
                            for(int b=-1;b<=1;b++){
                                if(j+a>=0 && j+a<m && k+b>=0 && k+b<m){
                                    if(j==k)
                                    cur[j][k]=max(cur[j][k],grid[i][j] + front[j+a][k+b]);
                                    else
                                    cur[j][k]=max(cur[j][k],grid[i][j] +grid[i][k] + front[j+a][k+b]);
                                }
                            }
                        }
                    }
                    // dp[i][j][k]=maxi;
                    
                }
            }
            front=cur;
        }
        return front[0][m-1];
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