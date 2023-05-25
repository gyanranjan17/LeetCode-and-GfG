//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prevl=0,prevr=0;
        for(int i=1;i<n;i++){
            int r=INT_MAX;
            int l=prevl+ abs(height[i]-height[i-1]);
            if(i>1){
            r=prevr+abs(height[i]-height[i-2]);
            }
            int cur=min(l,r);
            prevr=prevl;
            prevl=cur;
        }
        return prevl;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends