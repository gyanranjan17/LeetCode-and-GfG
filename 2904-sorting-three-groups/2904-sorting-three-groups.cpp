class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int prev,vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int c=nums[i];
        int ans=1e9;

        for(int k=prev;k<=3;k++){
            int y=f(i+1,k,nums);
            if(k!=c)
                y++;
            ans=min(ans,y);
        }
        return dp[i][prev]=ans;
        
    }
    int minimumOperations(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(4,-1));
        return f(0,1,nums);
    }
};