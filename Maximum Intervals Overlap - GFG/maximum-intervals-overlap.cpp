//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   // Your code goes here
	vector<pair<int, char>> v;

    for (int i = 0; i < N; ++i) {
        v.push_back({Entry[i], 'l'});
        v.push_back({Exit[i], 'r'});
    }

    sort(v.begin(), v.end());

    int ans = 0, res = 0, t = -1;

    for (auto& x : v) {
        if (x.second == 'l') 
            ans++;
        else 
            ans--;

        if (ans > res) {
            res = ans;
            t = x.first;
        }
    }

    return {res,t};
	   
	}

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends