#include <bits/stdc++.h>
using namespace std;
static bool sortByVal( pair<int, int> &a, pair<int, int> &b) 
  { 
      if(a.second != b.second)
      return a.second > b.second;
      
     if(a.first > b.first)
     return a.second > b.second;
    //  else
    //  return a.second < b.second;
  } 
int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        map<int, int> mpp;
        for(int i=0; i<n; i++){
             cin>>a[i];
             mpp[a[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto it : mpp)
        v.push_back(it);
        sort(v.begin(), v.end(), sortByVal);
        int j = 0;
        int i=0;
        for(auto it:v)
        {
            for(int j =0; j<it.second; j++)
           // a[i++] = it.first;
           cout<<it.first<< " ";
        }
        cout<<endl;
    }
    return 0;
};