//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
        bool dfs(vector<vector<char> >& board,int i,int j,string word,int ind,
        int m,int n){
            if(i>=m || i<0 || j>=n || j<0 ) return 0;
            if(word[ind]!=board[i][j]) return 0;
            if(ind==word.size()-1) return 1;
            vector<pair<int,int>>dirs={{-1,0},{-1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,-1},{1,1}};
            for(auto d:dirs){
                int nrow=i+d.first;
                int ncol=j+d.second;
                char ch=board[i][j];
                board[i][j]='-1';
                if(dfs(board,nrow,ncol,word,ind+1, m, n)){
                board[i][j]=ch;
                return 1;
                }
                
                board[i][j]=ch;
            }
            return 0;
        }
        bool exists(string word,vector<vector<char> >& board){
            int m=board.size();
            int n=board[0].size();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(dfs(board,i,j,word,0,m,n))
                    return true;
                }
            }
            return false;
            
        }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
        vector<string>ans;
        for(auto word:dictionary){
            if(exists(word,board)){
                ans.push_back(word);
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
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends