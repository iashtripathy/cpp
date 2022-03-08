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
    int start = -1;
    if(n%2) cout<<-1;
    else{
        for(int i=0;i<n-1;i+=2){
            start+=3;
            cout<<start<<" "<<--start<<" ";
        }
    }


    return 0;
}


