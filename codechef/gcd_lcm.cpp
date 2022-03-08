#include<bits/stdc++.h>
using namespace std;
long long find_gcd(int a,int b){
    if( b==0 )
    return a;
    return find_gcd(b,a%b);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long a,b;
        cin>>a>>b;
        long long gcd = find_gcd(a,b);
        long long prod = a*b;
        cout<<prod<<"\n";
        long long lcm = ( prod / gcd ) ;
        cout<<gcd<<" "<<lcm<<"\n";
    }
    return 0;
}