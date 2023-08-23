//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool f(int i, int j, int k, vector<vector<char>>&mat, string &w, string &dir){
        int n=mat.size();
        int m=mat[0].size();
        int sz=w.size();
        
        if(k==sz)return true;
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]!=w[k])return false;
        
        if(dir=="U" && f(i-1,j,k+1,mat,w,dir))return true;
        else if(dir=="D" && f(i+1,j,k+1,mat,w,dir))return true;
        else if(dir=="L" && f(i,j-1,k+1,mat,w,dir))return true;
        else if(dir=="R" && f(i,j+1,k+1,mat,w,dir))return true;
        else if(dir=="LUD" && f(i-1,j-1,k+1,mat,w,dir))return true;
        else if(dir=="LDD" && f(i+1,j-1,k+1,mat,w,dir))return true;
        else if(dir=="RUD" && f(i-1,j+1,k+1,mat,w,dir))return true;
        else if(dir=="RDD" && f(i+1,j+1,k+1,mat,w,dir))return true;
        
        return false;
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string w){
	    // Code here
	    vector<vector<int>> ans;
	    int n=grid.size(),m=grid[0].size();
	    vector<string>dir={"U","D","L","R","LUD","LDD","RUD","RDD"};
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            vector<int>temp(2,-1);
	            if(grid[i][j]==w[0]){
	                for(int k=0; k<8; k++){
	                    if(f(i,j,0,grid,w,dir[k])){
	                        ans.push_back({i,j});
	                        break;
	                    }
	                }
	            }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends