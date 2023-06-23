//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int target) {
        // Code here
        int l=0,r=N-1;
        while(l<=r){
            int m=(l+r)/2;
            if(target==nums[m]) return 1;
            if(nums[l]==nums[r] && nums[r]==nums[m]){
                l++;
                r--;
                continue;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<=target && target<=nums[m])
                r=m-1;
                else l=m+1;
            }
            else{
                if(nums[m]<=target && target<=nums[r])
                l=m+1;
                else r=m-1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends