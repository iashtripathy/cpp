#include<bits/stdc++.h>
using namespace std;
int main(){
    int edges,vertices;
    cin>>edges>>vertices;
    vector <int> v[vertices];
    int arr[2*edges];
    for(int i=0;i<(2*edges);i++){
        cin>>arr[i];
    }
    for(int i=0;i<(2*edges);i+=2){
        v[arr[i]].push_back(arr[i+1]);
    }
    for(int i=0;i<vertices;i++){
        for(const auto &j:v[i]){
            cout<<i<<"->"<<j<<endl;
        }
    }
    return 0;
}