//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int lcs(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        for(int i=0;i<text1.size()+1;i++){
            for(int j=0;j<text2.size()+1;j++){
                if(i==0 || j==0) dp[i][j]= 0;
                else{
                    if(text1[i-1]==text2[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                    else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
    int longestPalinSubseq(string A) {
        //code here
        string rs=string(A.rbegin(),A.rend());
        return lcs(A,rs);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends