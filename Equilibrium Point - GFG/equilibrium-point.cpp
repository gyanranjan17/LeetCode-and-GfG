//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
       int sum=0,rsum=0;
       if(n==1)
       return 1;
       for(int i=0;i<n;i++)
       {
           sum+=arr[i];
       }
       for(int i=n-1;i>=0;i--)
       {
           rsum+=arr[i];
           sum-=arr[i];
           if((sum-arr[i-1])==rsum)
           return i;
       }
       return -1;
    }

};



//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends