//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool cancol(int node,int color[],bool graph[101][101],int n,int col){
        for(int i=0;i<n;i++){
            if(i!=node && graph[i][node]==1 && color[i]==col) return 0;
        }
        return 1;
    }
    bool solve(int node,int color[],bool graph[101][101],int n,int m){
        if(node==n) return 1;
        for(int i=1;i<=m;i++){
            if(cancol(node,color,graph,n,i)){
            color[node]=i;
            if(solve(node+1,color,graph,n,m)) return 1;
            color[node]=0;
                
            }
        }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        if(solve(0,color,graph,n,m)) return 1;
        return 0;
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