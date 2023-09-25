class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26,0);
        int i;
        for(i=0;i<s.size();i++){
            v[s[i]-'a']+=1;
            v[t[i]-'a']-=1;
        }
        v[t[i]-'a']-=1;
        for(int k=0;k<26;k++) 
            if(v[k]!=0) return 'a'+k;
        return 'a';
    }
};