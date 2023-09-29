class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool in=0,ds=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) in=1;
            if(nums[i] <nums[i-1]) ds=1;
            if(in && ds) return 0;
        }
        return 1;
    }
};