//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i,vector<int>adj[],vector<int> &val){
        for(auto x:adj[i]){
            if(val[x]==-1){
                val[x]=!val[i];
                if(!dfs(x,adj,val)) return false;
            }
            else if( val[x]==val[i]) return false;
           
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> val(V,-1);
	    for(int i=0;i<V;i++){
           if(val[i]==-1){
               val[i]=0;
               if(!dfs(i,adj,val))
               return false;
           }
       }
       
       return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends