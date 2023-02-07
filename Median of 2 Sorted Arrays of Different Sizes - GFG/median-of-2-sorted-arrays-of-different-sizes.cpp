//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& a1, vector<int>& a2)
    {
        // Your code goes here
        int n1=a1.size(),n2=a2.size();
        int begin1 = 0, end1 = n1;
        if(n1>n2) return MedianOfArrays(a2,a1);

	while(begin1 <= end1)
	{
		int i1 = (begin1 + end1) / 2;
		int i2 = (n1 + n2 + 1) / 2 - i1;

		int min1 = (i1 == n1)?INT_MAX:a1[i1];
		int max1 = (i1 == 0)?INT_MIN:a1[i1 - 1];
		
		int min2 = (i2 == n2)?INT_MAX:a2[i2];
		int max2 = (i2 == 0)?INT_MIN:a2[i2 - 1];

		if(max1 <= min2 && max2 <= min1)
		{
			if((n1 + n2) % 2 == 0)
				return ((double)max(max1, max2) + min(min1, min2)) / 2;
			else
				return (double)max(max1, max2);
		}
		else if(max1 > min2)
			end1 = i1 - 1;
		else 
			begin1 = i1 + 1;
	}
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends