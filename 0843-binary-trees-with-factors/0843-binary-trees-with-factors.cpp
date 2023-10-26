class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long> mp;
        mp[arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            long long c=1;
            for(auto j:mp){
                int node=j.first;
                if(arr[i]%node==0 && mp.find(arr[i]/node)!=mp.end()){
                    c+=mp[node]*mp[arr[i]/node];
                }
            }
            mp[arr[i]]=c;
        }
        int ans=0;
        for(auto x:mp) ans=(ans+x.second)%mod;
        return ans;
    }
};