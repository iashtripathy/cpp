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
    int max_len = 1;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            cnt += 1;
        }
        else {
            cnt = 1;
        }
        max_len = max(max_len,cnt);
    }
    cout<<max_len;
    return 0;
}