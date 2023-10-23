class Solution {
public:
    int isFeasible(unordered_map<int, int> &freq, int groupSize){  
    int totalGroups = 0, highGroupSize = groupSize + 1;                
    for(auto [key, fq]:freq){
        int groupCount = fq / highGroupSize, remainder = fq % highGroupSize;         
        if(remainder > 0 && remainder < groupSize) {                 
            int requiredItem = groupSize - remainder;                
            if(groupCount < requiredItem) { return 0; }   
            groupCount +=1; 
            remainder = 0;                                           
        }
        totalGroups += groupCount + (remainder?1:0);                 
    }
    return totalGroups;
}

int minGroupsForValidAssignment(vector<int>& nums) {
    unordered_map<int, int> freq;
    int mn = INT_MAX, ans = nums.size();           
    for(auto n: nums) { freq[n]++; }               
    for(auto [k,v]:freq) { mn = min(mn, v); }     
    for(int groupSize = mn; groupSize >= 1; --groupSize){  
        int res = isFeasible(freq, groupSize);     
        if(res) return res;                       
    }
    return ans;   
}
};