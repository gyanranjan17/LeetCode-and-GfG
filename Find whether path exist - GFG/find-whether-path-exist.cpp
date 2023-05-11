//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool dfs(int&i,int&j,int&n,vector<vector<int>> &vis,vector<vector<int>> &grid){
        vis[i][j]=1;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        // if(grid[i][j]==2)
        // return 1;
        for(int x=0;x<4;x++){
            int nrow=i+drow[x];
            int ncol=j+dcol[x];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==2)
            return 1;
            else if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==3){
                if(dfs(nrow,ncol,n,vis,grid)) return 1;
            }
        }
        return 0;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            if(grid[i][j]==1 )
            return dfs(i,j,n,vis,grid);
        }
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends