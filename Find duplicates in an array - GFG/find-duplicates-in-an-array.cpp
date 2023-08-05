//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int nums[], int n) {
        // code here
        set<int> ans;
        vector<int> v;
        int i=0;
        while(i<n){
            while(nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }
            if(i!=nums[i])
            ans.insert(nums[i]);
            i++;
        }
        if(ans.size()){
            for(auto it:ans)
            v.push_back(it);
            return v;
        }
        return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends