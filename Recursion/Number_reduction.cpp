#include <bits/stdc++.h>
using namespace std;
int recursion(int x){
    if(x==3 || x<2){
        return x;
    }
    if(x>3 && x%2==0){
        return min(recursion(x-3),recursion(x/2));
    }
    else if(x>3){
        return recursion(x-3);
    }
    else{
        return recursion(x/2);
    }
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--)
	{
	    int x;
	    cin>>x;
	    cout<<recursion(x)<<endl;
	    
	}
	
	return 0;
}