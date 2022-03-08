#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    //endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long res = 0;
        int i = 0;

        for(int j=i+1;j<n;j++){
            if(arr[j]==0) continue;
            else if(arr[j]) {
                if(arr[j-1]){
                    i = j;
                    continue;
                }
                else{
                    res+=(j-i);
                    i = j;
                }
            }
        }                

        cout<<res<<endl;
        
        
    }

    return 0;
}


