//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int l, int r, int target){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
    
        while(l<=r){
            int m=(l+r)/2;
            if(target==nums[m]) return m;
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
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends