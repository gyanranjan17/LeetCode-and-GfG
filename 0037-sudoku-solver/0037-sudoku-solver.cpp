class Solution {
public:
    bool check(int i,int j,char ch,vector<vector<char>>& board){
        for(int k=0;k<9;k++){
            if(board[i][k]==ch) return 0;
            if(board[k][j]==ch) return 0;
            if(board[3*(i/3)+ k/3][3*(j/3)+k%3]==ch) return 0; 
        }
        return 1;
    }
    bool f(vector<vector<char>>& board){
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(check(i,j,ch,board)){
                            board[i][j]=ch;
                            if(f(board)) return 1;
                            else board[i][j]='.';
                        }
                    }
                    return 0;
                }      
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};