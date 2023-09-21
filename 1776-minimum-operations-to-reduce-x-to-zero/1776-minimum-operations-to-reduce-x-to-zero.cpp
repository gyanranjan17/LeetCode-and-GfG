class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int subsum=0,n=nums.size();
        for(auto i:nums) subsum+=i;
        int reqsum=subsum-x;
        int i=0,j=0,ans=1e9,tempsum=0;
        while(j<n && i<=j){
            tempsum+=nums[j];
            while(i<=j && tempsum>reqsum){
                tempsum-=nums[i];
                i++;
            }
            if(tempsum==reqsum){
                ans=min(ans,n+i-j-1);
            }
            j++;
        }
        if(ans==1e9) return -1;
        return ans;
    }
};