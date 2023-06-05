//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int i,int j, string &w1,string &w2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]){
            return dp[i][j]=f(i-1,j-1,w1,w2,dp);
        }
        return dp[i][j]=min(1+f(i,j-1,w1,w2,dp),min(1+f(i-1,j,w1,w2,dp),1+f(i-1,j-1,w1,w2,dp)));
    }
    int editDistance(string s, string t) {
        // Code here
        int m=s.size(),n=t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends