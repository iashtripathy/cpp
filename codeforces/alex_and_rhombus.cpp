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
    int an = 1+((n-1)*2);
    int upper_sum = (n*(1+an))/2;
    int ln = 1+((n-2)*2);
    int lower_sum = ((n-1)*(1+ln))/2;
    cout<<upper_sum+lower_sum;


    return 0;
}