#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int n,d;
    cin>>n>>d;
    string s;
    cin>>s;
    int x;
    vector<int> dp(n,inf);
    dp[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        if(s[i]-'0' == 1){
            x = inf;
            for(int j=i+1; j<=i+d ;j++){
                if(j<n){
                    x = min(dp[j],x);
                }
                else break;
                
            }
            if(x!=inf){
                dp[i] = 1+x;
            }

        }
    }
    if(dp[0]==inf) cout<<"-1";
    else cout<<dp[0];

    return 0;
}

/*
BEST SOLUTION
#include<bits/stdc++.h>
using namespace std;
int n,d,x,y;
string s;
main(){
cin>>n>>d>>s;
while(x<n-1&&y<=n){
    if(s[x]=='1')y++,x+=d;
    else x--;
}
cout<<(y>=n?-1:y);
}

*/