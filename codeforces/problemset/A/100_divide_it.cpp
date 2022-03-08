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
        long long n;
        cin>>n;
        int ch = true;
        int cnt = 0;
        while(ch){
            if(n%2==0){
                n = n/2;
                ++cnt;
                continue;
            }
            else if(n%3==0){
                n = (n/3)*2;
                ++cnt;
                continue;
            }
            else if(n%5==0){
                n = (n/5)*4;
                ++cnt;
                continue;
            }
            else{
                if(n==1) {
                    cout<<cnt<<endl;
                }
                else {
                    cout<<-1<<endl;
                }
                break;
            }
        }
    }
    return 0;
}


