class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back(vector<int>(i+1,1));
        }
        for(int i=2;i<n;i++){
            for(int j=1;j<v[i].size()-1;j++){
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
        return v;
    }
};