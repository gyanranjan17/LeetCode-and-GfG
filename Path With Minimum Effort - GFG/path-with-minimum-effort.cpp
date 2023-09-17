//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& h) {
        // Code here
        int n=h.size(),m=h[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> eff(n,vector<int>(m,1e9));
        int d[]={-1,0,1,0,-1};
        eff[0][0]=0;
        while(!pq.empty()){
            int ef=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1) return ef;
            for(int k=0;k<4;k++){
                int nr=r+d[k];
                int nc=c+d[k+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int nef=max(ef,abs(h[r][c]-h[nr][nc]));
                    if(eff[nr][nc]>nef){
                        eff[nr][nc]=nef;
                        pq.push({nef,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends