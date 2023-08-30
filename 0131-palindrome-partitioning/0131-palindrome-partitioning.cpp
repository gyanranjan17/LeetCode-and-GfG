class Solution {
public:
    bool check(string &p, int l, int r)
    {
       while(l<=r){
           if(p[l++]!=p[r--])return false;
       }
       return true;
    }
    void solve(int i, string &s, vector<vector<string>>&ans ,vector<string>&temp){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        string x="";
        for(int j=i; j<s.size(); j++){
            x+=s[j];
            if(check(s,i,j)){
              temp.push_back(x);
              solve(j+1,s,ans,temp);
              temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,ans,temp);
        return ans;

    }
};