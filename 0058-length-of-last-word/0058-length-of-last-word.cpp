class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool f=0;
        for(int i=s.length()-1;i>=1;i--){
            if(s[i]!=' '){
                count++;
                if(s[i-1]==' '){
                    f=1;
                    break;
                }
            }
                    
        }
        if(f==0) count++;
        return count;
    }
};