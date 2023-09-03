class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        // dp[0][0]=1;
        for(int row=0;row<m;row++){
            vector<int> temp(n,0);
            for(int col=0;col<n;col++){
                if(row==0 && col==0){
                    temp[col]=1;
                    continue;
                } 
                else
                {
                    int u=0,l=0;
                    if(row>0) u=dp[col];
                    if(col>0) l=temp[col-1];
                    temp[col]=l+u;
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
};