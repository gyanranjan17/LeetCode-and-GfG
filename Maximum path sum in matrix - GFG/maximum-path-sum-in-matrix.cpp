//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){
        int n=mat.size(),m=mat[0].size();
        if(j>=m || j<0) return -1;
        if(i==n-1) return dp[i][j]=mat[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=-1;
        for(int k=-1;k<=1;k++){
            maxi=max(maxi,mat[i][j]+f(i+1,j+k,mat,dp));
        }
        return dp[i][j]=maxi;
    }
    int maximumPath(int N, vector<vector<int>> mat)
    {
        // code here
        int m=mat[0].size();
        vector<vector<int>> dp(N,vector<int> (m,-1));
        int ans=0;
        for(int i=0;i<m;i++)
            ans=max(ans,f(0,i,mat,dp));
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends