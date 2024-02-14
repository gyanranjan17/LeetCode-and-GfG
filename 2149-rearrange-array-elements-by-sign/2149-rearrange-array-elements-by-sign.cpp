class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v(nums.size());
        int j=0,k=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
            v[j]=nums[i];
            j+=2;
            }
            else{
                v[k]=nums[i];
            k+=2;
            }
        }
        return v;
    }
};