class Solution {
public:
    vector<vector<int>> dp;
    static bool comp(string& a,string& b){
        return a.size() < b.size();
    }
    bool pred(string &s1,string &s2){
        int i=0,j=0,n1=s1.size(),n2=s2.size();
        if(s2.size()-s1.size()!=1) return 0;
        while(i<n1 && j<n2){
            if(s1[i]==s2[j]) i++;
            j++;
        }
        return i==n1;
    }
    int f(int prev,int i,vector<string>& words){
        if(i==words.size()) return 0;
        int x=0,y=0;
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        if(prev==-1 || pred(words[prev],words[i]))
        x= 1+f(i,i+1,words);
        y= f(prev,i+1,words);
        return dp[prev+1][i]=max(x,y);
    }
    int longestStrChain(vector<string>& words) {
        dp.resize(words.size(),vector<int>(words.size(),-1));
        sort(words.begin(),words.end(),comp);
        return f(-1,0,words);
    }
};