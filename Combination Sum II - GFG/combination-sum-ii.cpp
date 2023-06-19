//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void f(int ind,int t,vector<int> &ds,vector<vector<int>> &ans,vector<int>& can){
        if(t<0) return;
        if(t==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<can.size();i++){
            if(i!=ind && can[i]==can[i-1]) continue;

            ds.push_back(can[i]);
            f(i+1,t-can[i],ds,ans,can);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int> &can, int t) {
        // Write your code here
        sort(can.begin(),can.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,t,ds,ans,can);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends