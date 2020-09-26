#include<bits/stdc++.h>
//#include<iostream>
//#include<utility>
using namespace std;
int main(){
    int arr[4] = {20,40,30,10};
    vector <pair<int,int>> v;
    for(int i=0;i<4;i++){
        v.push_back({arr[i],i});
        //v.push_back(make_pair(arr[i],i));
    }   
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<","<<v[i].second<<endl;
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<","<<v[i].second<<endl;
    }    
    return 0;
}