//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        queue<vector<int>> q;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        q.push({0,0,0,k});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int r=v[0];
            int c=v[1];
            int lvl=v[2];
            if(r<0 || r>=n || c<0 || c>=m) continue;
            if(r==n-1 && c==m-1){
                return lvl;
            }
            if(mat[r][c]==1){
                if(v[3]>0) v[3]--;
                else continue;
            }
            if(vis[r][c]!=-1 && vis[r][c]>=v[3])
            continue;
            vis[r][c]=v[3];
            for(int i=0;i<4;i++){
                q.push({r+dr[i],c+dc[i],lvl+1,v[3]});
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends