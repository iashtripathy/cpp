#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    //endif

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int min_a = min({a,c,d});
    a-=min_a;
    c-=min_a;
    d-=min_a; 
    cout<<min_a*256 + min(a,b)*32;
    return 0;
}


