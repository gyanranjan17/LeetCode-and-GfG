class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string x=s+s;
        string y=x.substr(1,x.size()-2);
        if(y.find(s)!=-1)return true;
        return false;
    }
};