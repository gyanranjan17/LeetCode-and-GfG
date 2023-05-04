//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& ps) {
	    // Code here
	    vector<int> adj[n],ans;
        for(auto x:ps){
            adj[x.second].push_back(x.first);
        }
        
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j:adj[i])
            indeg[j]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int x:adj[u]){
                if(--indeg[x]==0)
                q.push(x);
            }
        }
        if(ans.size()==n) return 1;
        else return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends