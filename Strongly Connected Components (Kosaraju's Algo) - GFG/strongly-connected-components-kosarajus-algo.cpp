//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,stack<int> &st,vector<int> &vis,vector<vector<int>> &adj){
	    vis[i]=1;
	    for(auto u:adj[i]){
	        if(!vis[u])
	        dfs(u,st,vis,adj);
	    }
	    st.push(i);
	}
	void dfs2(int i,vector<int> &vis,vector<int> adjT[]){
	    vis[i]=1;
	    for(auto u:adjT[i])
	    if(!vis[u])
	    dfs2(u,vis,adjT);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs(i,st,vis,adj);
        }
        
        vector<int> adjT[V];
        for (int i=0;i<V;i++){
            vis[i]=0;
            for(auto u:adj[i])
            adjT[u].push_back(i);
        }
        
        int ans=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node,vis,adjT);
                ans++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends