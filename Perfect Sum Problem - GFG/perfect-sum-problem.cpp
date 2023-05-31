//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    if(arr[i]==0 && j==0) dp[i][j]= 2;
                    else if(j==0 || arr[0]==j) dp[i][j]= 1;
                    else dp[i][j]= 0;
                }
                else{
                    int np=dp[i-1][j]%mod;
                    int p=0;
                    if(arr[i]<=j)
                    p=dp[i-1][j-arr[i]]%mod;
                    dp[i][j]=(np+p)%mod;
                }
            }
        }
        return dp[n-1][sum];
        
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