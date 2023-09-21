//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            int mask=(1<<16)-1;
            d=d%16;
            vector<int> ans;
            // cout<<(n<<(16-d))<<endl;
            ans.push_back((n<<d | n>>(16-d)) &mask);
            ans.push_back((n>>d | n<<(16-d)) &mask);
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends