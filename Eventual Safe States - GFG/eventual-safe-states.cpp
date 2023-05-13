//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
      
        vector<int> adjr[V];
        vector<int> indeg(V,0);
        for(int i=0;i<V;i++){
            for(int u:adj[i]){
            adjr[u].push_back(i);
            indeg[i]++;
            
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<V;i++)
        if(indeg[i]==0)
        q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto x:adjr[u])
            if(--indeg[x]==0)
            q.push(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends