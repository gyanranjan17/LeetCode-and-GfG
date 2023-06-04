//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void f(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& mat) {
    int m = matrix.size(), n = matrix[0].size(),store=0;
    int d[] = {-1, 0, 1, 0, -1};
    for (int k = 0; k < 4; k++) {
        int nr = i + d[k];
        int nc = j + d[k + 1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            store+=mat[nr][nc];
            matrix[nr][nc] = 0;
        }
    }
    matrix[i][j]=store;
}

void MakeZeros(vector<vector<int>>& matrix) {
    vector<vector<int>> mat=matrix;
    int m = matrix.size(), n = matrix[0].size();
    int r, c;
    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        f(x.first,x.second,matrix,mat);
    }
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
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends