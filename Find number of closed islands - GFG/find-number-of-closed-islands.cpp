//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<int>>& mat,int r,int c){
        int N=mat.size(),M=mat[0].size();
        mat[r][c]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<N && nc<M && mat[nr][nc]==1){
                dfs(mat,nr,nc);
            }
        }
    }
    
    int closedIslands(vector<vector<int>>& mat, int N, int M) {
        // Code here
        for(int j=0;j<M;j++){
            if(mat[0][j]==1)
            dfs(mat,0,j);
            if(mat[N-1][j]==1)
            dfs(mat,N-1,j);
        }
        for(int i=1;i<N-1;i++){
            if(mat[i][0]==1)
            dfs(mat,i,0);
            if(mat[i][M-1]==1)
            dfs(mat,i,M-1);
        }
        int count=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(mat[i][j]==1){
                dfs(mat,i,j);
                count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends