class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int tmin=1e9,bmax=-1e9,lmin=1e9,rmax=-1e9;
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    tmin=min(tmin,i);
                    bmax=max(bmax,i);
                    lmin=min(lmin,j);
                    rmax=max(rmax,j);
                }
            }
        }
        int l= rmax-lmin+1;
        int b= bmax-tmin+1;
        return l*b;
    }
};