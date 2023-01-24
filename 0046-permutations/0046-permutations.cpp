class Solution {
public:
    void permute1(vector<int> &nums,int i,vector<vector<int>> &v)
    {
        if(i==nums.size()-1){
            v.push_back(nums);
        return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            permute1(nums,i+1,v);
            swap(nums[j],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        permute1(nums,0,v);
        return v;
    }

};