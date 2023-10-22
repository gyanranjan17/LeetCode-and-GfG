class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n),r(n);
        l[0]=nums[0],r[n-1]=nums[n-1];
        for(int i=1;i<n-1;i++){
            l[i]=min(l[i-1],nums[i]);
            r[n-1-i]=min(r[n-i],nums[n-i]);
        }
        int ans=1e9;
        for(int i=1;i<n-1;i++){
            if(l[i]<nums[i] && nums[i]>r[i]){
                ans=min(ans,nums[i]+l[i]+r[i]);
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};