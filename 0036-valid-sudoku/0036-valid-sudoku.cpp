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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    char x=board[i][j];
                    board[i][j]='.';
                    if(!check(i,j,x,board)) return 0;
                    board[i][j]=x;
                }
            }
        }
        return 1;
    }
};