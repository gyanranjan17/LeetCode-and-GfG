//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool f(int ind,int i,int j,vector<vector<char>>& board, string &word){
        if(ind==word.size()){
            return 1;
        }
        int dr[]={-1,0,1,0,-1};
        int dc[]={0,1,0,-1,0};
        if(word[ind]==board[i][j]){
            board[i][j]='0';
            if(f(ind+1,i,j,board,word)) return 1;
            board[i][j]=word[ind];
        }
        else{
            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]==word[ind]){
                    board[nr][nc]='0';
                    if(f(ind+1,nr,nc,board,word)) return 1;
                    board[nr][nc]=word[ind];
                }
            }
        }
        return 0;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(f(0,i,j,board,word))
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends