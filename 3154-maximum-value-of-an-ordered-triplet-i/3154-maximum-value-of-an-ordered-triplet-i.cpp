class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n=nums.size(),ans=0;
        vector<int> p(n),s(n);
        p[0]=nums[0];
        s[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            p[i]=max(nums[i],p[i-1]);
            s[n-i-1]=max(nums[n-i-1],s[n-i]);
        }
        for(int i=1;i<n-1;i++){
            if(p[i-1]>nums[i])
            ans=max(ans,(long long)(p[i-1]-nums[i])*s[i+1]);
        }
        return ans;
    }
};