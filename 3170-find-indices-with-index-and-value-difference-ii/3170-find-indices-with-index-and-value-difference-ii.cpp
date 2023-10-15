class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int ind, int val) {
        int i=0,j=ind;
        pair<int,int> mini={0,nums[0]},maxi={0,nums[0]};
        while(j<nums.size()){
            if(mini.second<nums[i]){
                mini.first=i;
                mini.second=nums[i];
            }
            if(maxi.second>nums[i]){
                maxi.first=i;
                maxi.second=nums[i];
            }
            if(abs(nums[j]-mini.second)>=val){
                return {mini.first,j};
            }
            else if(abs(nums[j]-maxi.second)>=val){
                return {maxi.first,j};
            }
            i++;
            j++;
        }
        return {-1,-1};
    }
};