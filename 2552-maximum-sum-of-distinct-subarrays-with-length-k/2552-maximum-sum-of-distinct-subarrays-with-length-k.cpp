class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,sum=0,i=0;
        unordered_map<int,int> mp;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            mp[nums[j]]++;
            if(j-i+1==k){
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};