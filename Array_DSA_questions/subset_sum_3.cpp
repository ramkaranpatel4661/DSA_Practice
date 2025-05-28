#include <bits/stdc++.h>
using namespace std;
bool recursion(int n , int arr[],int i,vector<int>&v){
    if(i>=n){
        if (v.empty()) return false; 
         int sum=0;
         for(int i=0;i<v.size();i++){
         sum+=v[i];   
         }
       if(sum%3==0){
        return true;
        }
        else{
         return false;   
        }
    }
    v.push_back(arr[i]);
   if( recursion(n,arr,i+1,v)){
       return true;
   }
   
      v.pop_back();
    if( recursion(n,arr,i+1,v)){
       return true;
   }
   return false;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    vector<int>v;
	    if(recursion(n,arr,0,v)){
	        cout<<"Yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	    
	}
	
	return 0;
}