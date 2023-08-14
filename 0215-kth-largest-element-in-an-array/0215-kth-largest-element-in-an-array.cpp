class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(auto x:nums)
        p.push(x);
        for(int i=1;i<k;i++)
        p.pop();
        return p.top();
    }
};