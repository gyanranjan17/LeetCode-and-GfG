class Solution {
public:
    bool isP(int gs,unordered_map<int,int> &mp,int &ans){
        int hgs=gs+1,tg=0;
        for(auto it:mp){
            int x=it.second;
            int gc=x/hgs,rem=x%hgs;
            if(rem>0 && rem<gs){
                if(gs-rem>gc) return 0;
                gc=gc+1;
            }
            tg+=gc;
            if(rem==gs) tg+=1;
        }
        ans=tg;
        return 1;
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        int gs=INT_MAX,ans=nums.size();
        for(auto it:mp) gs=min(gs,it.second);
        for(int i=gs;i>=1;i--){
            if(isP(i,mp,ans)) return ans;
        }
        return ans;
    }
};