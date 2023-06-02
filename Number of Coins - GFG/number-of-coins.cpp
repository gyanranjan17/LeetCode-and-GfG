//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:

	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M,vector<int>(V+1,-1));
	    for(int i=0;i<M;i++){
	        for(int j=0;j<V+1;j++){
	            if(i==0){
        	        if(j%coins[i]==0) dp[i][j]=j/coins[i];
        	        else dp[i][j]= 1e9;
        	    }
        	    else{
            	    int np=dp[i-1][j];
            	    int p=1e9;
            	    if(coins[i]<=j)
            	    p=1+dp[i][j-coins[i]];
            	    dp[i][j]=min(p,np);
        	    }
	        }
	    }
	    if(dp[M-1][V]>=1e9) return -1;
	    return dp[M-1][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends