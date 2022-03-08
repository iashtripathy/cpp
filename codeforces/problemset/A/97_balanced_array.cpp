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
        n = n/2;
        if(n%2!=0) cout<<"NO"<<endl;
        else{
            int i;
            cout<<"YES"<<endl;
            for(i=1;i<=n;i++){
                cout<<2*i<<" ";
            }
            for(i=1;i<=n-1;i++){
                cout<<(2*i)-1<<" ";
            }            
            cout<<3*i-1<<endl;
        }
    }
    return 0;
}


