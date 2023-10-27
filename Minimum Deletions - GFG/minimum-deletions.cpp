//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(int i,int j,string &a,string &s,vector<vector<int>> &dp){
        int n=a.size();
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==s[j]){
            return dp[i][j]= 1+lcs(i+1,j+1,a,s,dp);
        }
        else{
            return dp[i][j]=max(lcs(i+1,j,a,s,dp),lcs(i,j+1,a,s,dp));
        }
    }
    int minimumNumberOfDeletions(string s) { 
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        string a=s;
        int ans=0;
        reverse(s.begin(),s.end());
        return s.size()-lcs(0,0,a,s,dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends