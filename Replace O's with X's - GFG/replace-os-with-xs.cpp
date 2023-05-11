//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<int>> &vis,vector<vector<char>> &mat,int i,int j,int &m,int &n){
        vis[i][j]=1;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        for(int x=0;x<4;x++){
            int nrow=i+drow[x];
            int ncol=j+dcol[x];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O' && !vis[nrow][ncol])
            dfs(vis,mat,nrow,ncol,m,n);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O')
            dfs(vis,mat,0,j,m,n);
            
            if(!vis[n-1][j] && mat[n-1][j]=='O')
            dfs(vis,mat,n-1,j,m,n);
        }
        for(int i=1;i<n-1;i++){
            if(!vis[i][0] && mat[i][0]=='O')
            dfs(vis,mat,i,0,m,n);
            
            if(!vis[i][m-1] && mat[i][m-1]=='O')
            dfs(vis,mat,i,m-1,m,n);
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && mat[i][j]=='O')
                mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends