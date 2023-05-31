//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    
    bool isSubsetSum(int arr[],vector<vector<int>> &dp,int N,int sum){
    
        for(int i=0;i<N;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=(j==arr[0]);
                else{
                   if(i>0){
                    int nt=dp[i-1][j];
                    int t=0;
                    if(j>=arr[i])                         //    Space optimisation will be done
                    t=dp[i-1][j-arr[i]];
                    dp[i][j]=(nt || t);
                   }
                }
            }
        }
        return dp[N-1][sum];
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int S=0;
        for(int i=0;i<n;i++)
        S+=arr[i];
        vector<vector<int>> dp(n,vector<int>(S/2+1,0));
        isSubsetSum(arr,dp,n,S/2);
        int t;
        for(int j=S/2;j>=0;j--)
        {
            if(dp[n-1][j]==1){
            t=j;
            break;
            }
        }
        return S-t-t;
	}
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends