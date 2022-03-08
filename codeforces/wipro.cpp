#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>s;
    int j=1;
    s.push(arr[0]);
    while(j<n){
        while(s.size()>=1 && arr[j]>s.top()){
            ++j;
            if(j>=n) break;
        }
        if(j>=n) break;
        s.push(arr[j]);
        ++j;
    }
   
    vector<int>res;
    while(!s.empty()){
        res.push_back(s.top());
        //cout<<s.top()<<" ";
        s.pop();
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}