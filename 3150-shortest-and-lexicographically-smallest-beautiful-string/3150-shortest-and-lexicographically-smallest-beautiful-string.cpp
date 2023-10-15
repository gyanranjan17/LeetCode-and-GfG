class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int i=0,j=0,c=0,len=1e9;
        while(j<s.size()){
            if(s[j]=='1') c++;
            while(c>=k){
                if(c==k){
                    if(j-i+1<len){
                        len=j-i+1;
                        ans=string(s.begin()+i,s.begin()+j+1);
                    }
                    else if(j-i+1==len){
                        string temp=string(s.begin()+i,s.begin()+j+1);
                        if(ans>temp)
                        ans=temp;
                    }
                }
                if(s[i]=='1')
                    c--;
                i++;
            }
            j++;
        }
        return ans;
    }
};