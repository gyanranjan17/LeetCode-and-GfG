//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod=1e9+7;
    //Function to count number of ways to reach the nth stair.
    
    int countWays(int n)
    {
        // your code here
        int prev1,prev2,curr;
        for(int i=0;i<=n;i++){
            
            if(i==0 || i==1) curr=1;
            else {
                int one=prev1;
                int two=prev2;
                curr=(one+two)%mod;
            }
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends