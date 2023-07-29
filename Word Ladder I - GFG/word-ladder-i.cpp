//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end()); 
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string s=q.front().first;
            int lvl=q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++){
                char ch=s[i];
                for(char j='a';j<='z';j++){
                    s[i]=j;
                    if(st.find(s)!=st.end()) {
                        st.erase(s);
                        q.push({s,lvl+1});
                        if(s==endWord) return lvl+1;
                    }
                }
                s[i]=ch;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends