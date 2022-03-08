#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    int arr_size = s.size();
    int arr[arr_size+1];
    arr[0] = 0;
    for(int i=1;i<=arr_size;i++){
        arr[i] = arr[i-1]+(s[i-1] - 96);
    }
    
    while(q--){
        int a,b,count=0;
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<"\n";
    }
    return 0;
}