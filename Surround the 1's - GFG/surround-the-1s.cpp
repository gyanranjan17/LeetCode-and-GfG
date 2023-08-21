//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& mat) {
        // Code here
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};
        int n=mat.size(),m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) continue;
                int zc=0;
                for(int k=0;k<8;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==0){
                        zc++;
                    }
                }
                if(zc%2==0 && zc!=0) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends