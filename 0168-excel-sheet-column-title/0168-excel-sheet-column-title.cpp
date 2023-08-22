class Solution {
public:
    string convertToTitle(int cn) {
        string ans="";
        while(cn){
            int d=cn%26;
            cn/=26;
            if(d==0) {d=26;cn--;}
            ans+='A'+d-1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};