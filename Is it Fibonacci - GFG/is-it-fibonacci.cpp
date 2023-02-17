//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> geek_num) {
        // code here
    if (n <= k) return geek_num[n-1];
    long long i=0,j=0,sum=0;
    while(j<k){
    sum+=geek_num[j];
    j++;
    }
    while(j<n-1){
        geek_num.push_back(sum);
        sum+=sum;
        sum-=geek_num[i];
        i++;
        j++;
    }
    return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends