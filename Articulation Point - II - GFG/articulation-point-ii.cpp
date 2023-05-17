//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int timer=0;
    void dfs(int node,int parent,vector<int> &mark,vector<int> &low,vector<int> &tin,vector<int>adj[],vector<int> &vis){
        vis[node]=1;
        low[node]=tin[node]=++timer;
        int child=0;
        for(auto x:adj[node]){
            if(x==parent) continue;
            if(!tin[x]){
                dfs(x,node,mark,low,tin,adj,vis);
                low[node]=min(low[node],low[x]);
                if(low[x]>=tin[node] && parent!=-1)
                mark[node]=1;
                child++;
            }
            else{
                low[node]=min(low[node],tin[x]);
            }
        }
        if(child>1 && parent==-1)
        mark[node]=1;
    }
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        // Code here
        vector<int> mark(v,0),low(v),tin(v,0),vis(v,0);
        
        for(int i=0;i<v;i++){
             if(!vis[i])
             dfs(i,-1,mark,low,tin,adj,vis);
        }
        vector<int> ans;
        for(int i=0;i<v;i++)
            if(mark[i]==1)
            ans.push_back(i);
        if(ans.size()==0)
        return {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends