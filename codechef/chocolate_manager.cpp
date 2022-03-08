#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int T;
    cin>>T;
	while(T--){
	    int n,x;
	    cin>>n>>x;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    //int count = 0;
	    unordered_map <int,int> um;
	    for(int i=0;i<n;i++){
	        if(um.find(arr[i])==um.end()){
	            um[arr[i]] = 1;
	        }
	    }
	    if(n-x <= um.size()){
	        cout<<n-x;
	    }
	    else{
	        cout<<um.size();
	    }
	    cout<<"\n";
	}
	return 0;
}
