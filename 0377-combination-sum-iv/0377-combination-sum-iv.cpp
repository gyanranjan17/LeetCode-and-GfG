class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int t,vector<int> &nums)
    {
        if(t < 0) return 0;
        if(t == 0) return 1;
        if(dp[i][t]!=-1) return dp[i][t];
        int ways = 0;  
        for(int k = 0; k<nums.size(); k++)
            ways += f(k, t - nums[k], nums);
        return dp[i][t]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(nums.size(),vector<int> (target+1,-1));
        return f(0,target,nums);
    }
};