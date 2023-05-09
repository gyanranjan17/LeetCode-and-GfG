//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Code here 
        int m=image.size();
        int n=image[0].size();
        // vector<vector<int>> ans( m , vector<int> (n, 0));
        // ans[sr][sc]=color;
        int x=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dcol[]={-1,0,1,0};
        int drow[]={0,-1,0,1};
        while(q.empty()==0){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]!=color && (image[nrow][ncol]==x)){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                    }
            }
            
        }
        image[sr][sc]=color;
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends