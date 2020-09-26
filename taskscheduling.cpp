#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool mycmp(pair<long long int,char>p1,pair<long long int,char>p2){
    //if both has same time then the one with Arrival time has to be put first in the sorted order
    if(p1.first==p2.first){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main() {
	//code
	long long int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int enter[n];
	    long long int exitt[n];
	    for(long long int i = 0;i<n;i++){
	        cin>>enter[i];
	    }
	    for(long long int i = 0;i<n;i++){
	        cin>>exitt[i];
	    }

	    vector<pair<long long int,char>> v;
	    
	    for(long long int i =0;i<n;i++){
	        v.push_back({enter[i],'A'});
	    }
	    for(long long int i =0;i<n;i++){
	        v.push_back({exitt[i],'D'});
	    }
	    sort(v.begin(),v.end(),mycmp);
	    long long int cur = 0,ans=0,t=0;
	    for(auto &x:v){
	        if(x.second=='A'){
	            cur = cur + 1;
	        }
	        else if(x.second=='D'){
	            cur = cur - 1;
	        }
	        if(cur>ans){
	            ans = cur;
	            t = x.first;
	        }
	    }
	    cout<<ans<<" "<<t<<endl;
	}
	return 0;
}