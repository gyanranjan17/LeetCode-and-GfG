class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool in=1,ds=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) ds=0;
            if(nums[i] <nums[i-1]) in=0;
            if(!in && !ds) return 0;
        }
        return 1;
    }
};