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
        long long n,q;
        cin>>n>>q;
        long long arr[n];
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        while(q--){
            long long l,r;
            cin>>l>>r;
            l = l-1;
            r = r-1;
            for(long long i = 0;i<n-1;i++){
                if(i==l){
                    i = r;
                    continue;
                }
                if(i+1==l){
                    if(r!=n-1){
                        arr[r+1] = find_gcd(arr[i],arr[r+1]);
                        i = r;
                        continue;
                    }
                    else{
                        arr[r] = arr[l-1];
                    }
                }   
                else{
                    arr[i+1] = find_gcd(arr[i],arr[i+1]);
                }
                
            }
            cout<<arr[n-1]<<endl;

        }
    }
    return 0;
}