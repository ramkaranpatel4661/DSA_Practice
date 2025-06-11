#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    map<int,int> mp;
	    string ans="Yes";
	    for(int i=0;i<n;i++){
	        if(s[i]=='0'){
	            if(i>0 && s[i-1]=='1' && mp[i-1]<1){
	                mp[i-1]=1;
	            }
	            else if(i<n-1 && s[i+1]=='1'){
	                mp[i+1]=1;
	            }
	            else{
	                ans="No";
	                break;
	            }
	        }
	    }
	    cout<<ans<<endl;
	}

}