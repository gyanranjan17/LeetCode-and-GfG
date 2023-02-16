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
    if (n <= k) {
        return geek_num[n-1];
    }
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += geek_num[i];
    }
    for (int i = k; i < n; i++) {
        long long next_num = sum;
        sum += next_num - geek_num[i%k];
        geek_num[i%k] = next_num;
    }
    return geek_num[(n-1)%k];
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