class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int sc=nums[0];
        for(int i=1;i<nums.size();i++) sc=sc&nums[i];
        if(sc!=0) return 1;
        int ans=0,a=nums[0];
        for(int i=1;i<nums.size();i++){
            if(a==sc){
                ans++;
                a=nums[i];
                continue;
            }
            a=a&nums[i];
        }
        if(a==0) return ans+1;
        return ans;
    }
};