//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
      vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>ans(N,10000);
        ans[0] = 0;
        for(int i=0;i<M;i++)
        {
          ans[edges[i][1]] = min(ans[edges[i][1]],ans[edges[i][0]]+edges[i][2]);
        }
        for(int i=0;i<N;i++)
        {
            if(ans[i]==10000)
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends