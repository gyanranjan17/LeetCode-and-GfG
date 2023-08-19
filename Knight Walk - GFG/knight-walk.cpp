//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&k, vector<int>&t, int n){
	    // Code here
	    vector<vector<int>> vis(n+1,vector<int>(n+1,0));
	    queue<pair<int,int>> q;
	    q.push({k[0],k[1]});
	    int dr[]={1,1,-1,-1,2,2,-2,-2};
	    int dc[]={2,-2,2,-2,1,-1,1,-1};
	    vis[k[0]][k[1]]=1;
	    int st=-1;
	    while(!q.empty()){
	        int sz=q.size();
	        st++;
	        while(sz--){
	            int r=q.front().first;
	            int c=q.front().second;
	            if(t[0]==r && t[1]==c) return st;
	            q.pop();
	            for(int i=0;i<8;i++){
	                int nr=r+dr[i];
	                int nc=c+dc[i];
	                if(nr>0 && nc>0 && nr<=n && nc<=n && !vis[nr][nc]){
	                    vis[nr][nc]=1;
	                    q.push({nr,nc});
	                }
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends