class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            bool flag=1;
            string x=s.substr(0,i+1);
            for(int j=i+1;j<n;j+=i+1){
                string y=s.substr(j,i+1);
                if(x!=y) {
                    flag=0;
                    break;
                }
            }
            if(flag) return 1;
        }
        return 0;
    }
};