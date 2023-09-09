#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int ans=0;
	    for(int i=0;i<s.size();i++){
	        int ls=0,rs=0;
	        for(int j=0;i-j>=0 && i+j+1<s.size();j++){
	            ls+=s[i-j];
	            rs+=s[i+j+1];
	            if(ls==rs) ans=max(ans,2*(j+1));
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}