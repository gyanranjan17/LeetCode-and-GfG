//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<int> &vis,vector<int> adj[],int x,int n){
        vis[x]=1;
        for(auto i:adj[x]){
            if(!vis[i])
            dfs(vis,adj,i,n);
        }
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
       
        int m=edge.size();
         if(m<n-1) return -1;
        vector<int> adj[n];
        for(auto j:edge){
            adj[j[0]].push_back(j[1]);
            adj[j[1]].push_back(j[0]);
        }
        int count=0;
        vector<int> vis(n,0);
            for(int x=0;x<n;x++){
                if(!vis[x]){
                dfs(vis,adj,x,n);
                count++;
                }
            }
        return count-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends