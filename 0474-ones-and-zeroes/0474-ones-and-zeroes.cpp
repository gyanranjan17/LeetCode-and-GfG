class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i, vector<vector<int>>& str, int n, int m){
        if(i==str.size()) return 0;
        if(dp[i][n][m]!=-1) return dp[i][n][m];
        if(n>=str[i][0] && m>=str[i][1]){
            return dp[i][n][m]=max(1+f(i+1,str,n-str[i][0],m-str[i][1]),f(i+1,str,n,m));
        }
        return dp[i][n][m]=f(i+1,str,n,m);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size(),vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        vector<vector<int>> str;
        for(string i:strs){
            vector<int> temp;
            temp.push_back(count(i.begin(),i.end(),'1'));
            temp.push_back(count(i.begin(),i.end(),'0'));
            str.push_back(temp);
        }
        return f(0,str,n,m);
    }
};