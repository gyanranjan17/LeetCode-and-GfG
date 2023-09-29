class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> rev=nums;
        sort(rev.begin(),rev.end());
        if(rev==nums) return 1;
        sort(rev.rbegin(),rev.rend());
        if(rev==nums) return 1;
        return 0;
    }
};