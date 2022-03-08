#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    //endif

    int n;
    cin>>n;
    int arr[n][3];
    int cnt = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) ++temp;
        }
        if(temp>=2) ++cnt;
    }
    cout<<cnt;
    return 0;
}


