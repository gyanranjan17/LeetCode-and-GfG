//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, pair<int, int> src,
                     pair<int, int> des) {
        // code here
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[src.first][src.second]=true;
        q.push({src.first,src.second});
        vector<int>dir={0,-1,0,1,0};
        int ans=0;
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                auto node=q.front();
                q.pop();
                int i=node.first;
                int j=node.second;
                
                if(i==des.first && j==des.second)return ans;
                
                for(int k=0; k<4; k++){
                    int x=i+dir[k];
                    int y=j+dir[k+1];
                    
                    if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && mat[x][y]==1){
                        vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
            ans++;
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends