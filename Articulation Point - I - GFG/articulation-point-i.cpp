//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=0;
    void dfs(int node,int parent,vector<int> &mark,vector<int> &low,vector<int> &tin,vector<int>adj[]){
        low[node]=tin[node]=++timer;
        int child=0;
        for(auto x:adj[node]){
            if(x==parent) continue;
            if(!tin[x]){
                dfs(x,node,mark,low,tin,adj);
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
        vector<int> mark(v,0),low(v),tin(v,0);
        dfs(0,-1,mark,low,tin,adj);
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