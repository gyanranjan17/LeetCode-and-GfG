//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long res=0,c;
        stack<long long> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<=arr[s.top()]){
            long long y=s.top();
            s.pop();
            c= arr[y]*(s.empty() ? i:(i-s.top()-1));
            res=max(c,res);
            }
            s.push(i);
        }
        while(!s.empty()){
            long long x=s.top();
            s.pop();
            c= arr[x]*(s.empty() ? n:(n-s.top()-1));
            res=max(c,res); 
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends