class Solution {
public:
    long long minimumSteps(string s) {
        long long i=0,j=1,ans=0;
        while(j<s.size()){
            while(s[i]=='0' && i<j) {
                i++;
            }
            if(s[j]=='0'){
                swap(s[i],s[j]);
                ans+=j-i;
                i++;
            }
            j++;
        }
        return ans;
    }
};  