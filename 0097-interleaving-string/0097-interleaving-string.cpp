class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool f(int i,int j,int ind,string &s1,string &s2,string &s3){
        if(ind==s3.size()){
            if(i>=s1.size() && j>=s2.size()) return 1;
            return 0;
        }
        if(dp[i][j][ind]!=-1) return dp[i][j][ind];
        bool x=0,y=0;
        if(i<s1.size() && s1[i]==s3[ind]){
            x=f(i+1,j,ind+1,s1,s2,s3);
        }
        if(j<s2.size() && s2[j]==s3[ind]){
            y=f(i,j+1,ind+1,s1,s2,s3);
        }
        return dp[i][j][ind]=(x || y);
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size(),-1)));
        return f(0,0,0,s1,s2,s3);
    }
};