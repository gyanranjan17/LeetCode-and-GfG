//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     bool possible(vector<int>& piles,int mid,int h){
        int b;
        for(int i=0;i<piles.size();i++){
            if(mid>piles[i]) b=1;
            else if(piles[i]%mid==0)
            b=piles[i]/mid;
            else if(piles[i]%mid!=0)
            b=piles[i]/mid+1;
            h=h-b;
        }
        return (h<0) ? 0:1;
    }
    int Solve(int N, vector<int>& piles, int h) {
        // Code here
        int l=1,r=0;
        int mod=1e9+7;
        for(int i=0;i<N;i++){
            r=(r+piles[i])%mod;
        }
        int res=r;
        while(l<=r){
            int mid=l+ (r-l)/2;
            if(possible(piles,mid,h)){
                r=mid-1;
                res=mid;
            }
            else{
                l=mid+1;
            }
        }
        return res;
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends