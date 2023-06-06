//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool f(int i,int j,string &p, string &s,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i==0 && j>0) return 0;
        if(j==0 && i>0) {
            for(int k=0;k<=i-1;k++){
                if(p[k]!='*') return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[i-1]==s[j-1] || p[i-1]=='?') return dp[i][j]= f(i-1,j-1,p,s,dp);
        if(p[i-1]=='*') return dp[i][j]= (f(i-1,j,p,s,dp) | f(i,j-1,p,s,dp));
        return dp[i][j]= 0;
    }
    int wildCard(string p,string s)
    {
        int m=p.size(),n=s.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m,n,p,s,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends