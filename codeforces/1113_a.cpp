#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    
    int pre_petrol = 0,cost = 0,i=1;
    while( pre_petrol < n-i ){
        int diff = min(v - pre_petrol,(n-1)-pre_petrol);
        pre_petrol += diff;
        cost += i*diff;
        pre_petrol--;
        i++;
    }
    cout<<cost;
    return 0;
}