class Solution {
public:
    // int f(int i,int prev_i,vector<int> &nums,vector<vector<int>> &dp){
    //     if(i==nums.size()) return 0;

    //     if(dp[i][prev_i+1]!=-1) return dp[i][prev_i+1];
    //     int nt=f(i+1,prev_i,nums,dp);
    //     int t=INT_MIN;
    //     if(prev_i==-1 || nums[i]>nums[prev_i])
    //     t=1+f(i+1,i,nums,dp);
    //     return dp[i][prev_i+1]=max(nt,t);
    // }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        for(int i=nums.size();i>=0;i--){
            for(int prev=nums.size()-1;prev>=-1;prev--){
                if(i==nums.size()) dp[i][prev+1]=0;
                else if(prev==nums.size()-1) dp[i][prev]=0;
                else{
                    int nt=dp[i+1][prev+1];
                    int t=0;
                    if(prev==-1 || nums[i]>nums[prev])
                    t=1+dp[i+1][i+1];
                    dp[i][prev+1]=max(nt,t);
                }
            }
        }
        
        return dp[0][0];
    }
};