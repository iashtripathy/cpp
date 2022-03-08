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
        int arr1[n],arr2[n];
        
        int min_b = INT_MAX;
        int min_a = INT_MAX;
        for(int i=0;i<n;i++){
            cin>>arr1[i];
            min_a = min(min_a,arr1[i]);

        }
        
        for(int i=0;i<n;i++){
            cin>>arr2[i];
            min_b = min(min_b,arr2[i]);
        }
        long long cnt = 0;
        for(int i=0;i<n;i++){
            cnt+=max({arr1[i]-min_a,arr2[i]-min_b});
        }
        cout<<cnt<<endl;
        
    }
    return 0;
}


