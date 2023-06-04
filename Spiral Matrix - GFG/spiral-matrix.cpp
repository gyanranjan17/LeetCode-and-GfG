//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int m, int n, int k)
    {
        // Your code goes here
        int top=0,bottom=m-1,right=n-1,left=0;
        int ans=0;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
            ans++;
            if(ans==k) return a[top][i];
            }
            top++;
            for(int i=top;i<=bottom;i++){
            ans++;
            if(ans==k) return a[i][right];
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                ans++;
                if(ans==k) return a[bottom][i];
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                ans++;
                if(ans==k) return a[i][left];
                }
                left++;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends