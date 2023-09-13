class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for(auto i:s) v[i-'a']++;
        sort(v.rbegin(),v.rend());
        int ans=0;
        for(int i=1;i<26;i++)
        {
            if(v[i]==0) continue;
            if(v[i-1]<=v[i]){
                int p=v[i];
                v[i]=max(0,v[i-1]-1);
                ans+=p-v[i];   
            }
        }
        return ans;
    }
};