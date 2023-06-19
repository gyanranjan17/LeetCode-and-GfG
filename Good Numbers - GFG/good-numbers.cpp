//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isValid(int i , int D)
    {
        int sum = 0;
        
        while(i)
        {
            int last = i%10;
            if(last == D)return false;
            sum += last;
            i /= 10;
            if(i==0)break;
            last = i%10;
            if(last<=sum)return false;
        }
        
        return true;
    }
  
    vector<int> goodNumbers(int L, int R, int D) {
        
        vector<int> ans;
        for(int i=L;i<=R;i++)
        {
            if(isValid(i,D))ans.push_back(i);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends