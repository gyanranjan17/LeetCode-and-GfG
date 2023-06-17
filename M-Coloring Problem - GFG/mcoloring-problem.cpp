//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool cancolor(int node,int i,vector<int> &col,bool graph[101][101],int n){
        for(int k=0;k<n;k++){
            if( graph[node][k]==1 && col[k]==i) return 0;
        }
        return 1;
    }
    bool f(int node,bool graph[101][101],int m,int n,vector<int>&col){
        if(node==n) return 1;
        
        for(int i=1;i<=m;i++){
            if(cancolor(node,i,col,graph,n)){
                col[node]=i;
                if(f(node+1,graph,m,n,col)) return 1;
                col[node]=0;
            }
         
        }
         return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> col(n,-1);
        return f(0,graph,m,n,col);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends