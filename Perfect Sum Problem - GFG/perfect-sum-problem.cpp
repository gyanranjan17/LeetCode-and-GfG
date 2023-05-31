//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
    int f(int i,int sum,int arr[],vector<vector<int>> &dp){
        if(i==0) {
            if(arr[i]==0 && sum==0) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            return 0;
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int np=f(i-1,sum,arr,dp)%mod;
        int p=0;
        if(arr[i]<=sum)
        p=f(i-1,sum-arr[i],arr,dp)%mod;
        return dp[i][sum]=(np+p)%mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return f(n-1,sum,arr,dp);
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends