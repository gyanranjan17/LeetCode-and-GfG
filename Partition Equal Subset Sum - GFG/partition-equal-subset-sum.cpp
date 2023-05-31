//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int sum,int N){
    
        vector<vector<int>> dp(N,vector<int>(sum+1,0));
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
    int equalPartition(int N, int arr[])
    {
        // code here
        int S=0;
        for(int i=0;i<N;i++)
        S+=arr[i];
        if(S%2) return 0;
        return isSubsetSum(arr,S/2,N);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends