//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int r=0,c=M-1,count=0,m=0,x;
            while(r<N && c>=0){
                for( ;c>=0;c--){
                    if(Mat[r][c]==1)
                    count++;
                    if(count>m){
                        m=count;
                        x=r;
                    }
                }
                r++;
                c=M-1;
                count=0;
            }
            return x;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends