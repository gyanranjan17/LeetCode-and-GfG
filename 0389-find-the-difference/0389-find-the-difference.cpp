class Solution {
public:
    char findTheDifference(string s, string t) {
       int y=0;
       for(auto i:s)
       y^=i;
       for(auto j:t) y^=j;
        return y;
    }
};