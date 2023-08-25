class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool f(int i,int j,int ind,string &s1,string &s2,string &s3){
        if(i>=s1.size() && j>=s2.size() && ind<s3.size()) return 0;
        if(s1[i]!=s3[ind] && s2[j]!=s3[ind]) return 0;
        if(ind==s3.size() && i>=s1.size() && j>=s2.size()) return 1;
        if(dp[i][j][ind]!=-1) return dp[i][j][ind];
        bool x=0,y=0;
        if(s1[i]==s3[ind]){
            x=f(i+1,j,ind+1,s1,s2,s3);
        }
        if(s2[j]==s3[ind]){
            y=f(i,j+1,ind+1,s1,s2,s3);
        }
        return dp[i][j][ind]=(x || y);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()>s3.size() || s2.size()>s3.size()) return 0;
        dp.resize(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return f(0,0,0,s1,s2,s3);
    }
};