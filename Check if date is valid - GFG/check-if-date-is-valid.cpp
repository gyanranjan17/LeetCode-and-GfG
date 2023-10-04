//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int isValidDate(int d, int m, int y) {
        // code here
        if(d<1 || d>31) return 0;
        if(m<1 || m>12) return 0;
        if(y<1800 || y>9999) return 0;
        if(m==2) {
            if(y%4==0) return d<=29;
            else return d<=28;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d,m,y;
        
        cin>>d>>m>>y;

        Solution ob;
        cout << ob.isValidDate(d,m,y) << endl;
    }
    return 0;
}
// } Driver Code Ends