class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int th=INT_MIN;
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<th) return 1;
            while(!s.empty() && nums[i]>s.top()){
                th=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return 0;
    }
};