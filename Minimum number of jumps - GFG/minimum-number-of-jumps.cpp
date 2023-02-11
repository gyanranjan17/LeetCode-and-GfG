//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    bool canReach(int A[], int N) {
        int i=0;
        for(int reach=0;i<N && i<=reach;i++)
        reach=max(reach,A[i]+i);
        return i==N;
    }
    
    int minJumps(int arr[], int n){
        if( canReach(arr,n)){
            for(int i = 1; i < n; i++)
            arr[i] = max(arr[i] + i, arr[i-1]);
            int ind=0,c=0;
            while(ind<n-1){
            ind=arr[ind];
            c++;
            }
            return c;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends