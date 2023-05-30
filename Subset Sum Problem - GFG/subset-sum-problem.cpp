//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool f(int i,int sum,vector<int>&arr,vector<vector<int>> &dp){
    //     if(sum==0) return dp[i][sum]=1;
    //     if(i==0) return dp[i][sum]=(sum==arr[i]);
    //     if(dp[i][sum]!=-1) return dp[i][sum];
    //     int nt=f(i-1,sum,arr,dp);
    //     int t=0;
    //     if(sum>=arr[i])                                     
    //     t=f(i-1,sum-arr[i],arr,dp);
    //     return dp[i][sum]=(nt | t);
        
    // }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<sum+1;j++){
                    int nt=dp[i-1][j];
                    int t=0;
                    if(j>=arr[i])                         //    Space optimisation will be done
                    t=dp[i-1][j-arr[i]];
                    dp[i][j]=(nt || t);
                
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<sum+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends