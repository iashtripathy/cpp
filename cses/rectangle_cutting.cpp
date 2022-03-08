#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //endif

    int a,b;
    cin>>a>>b;
    int dp[a+1][b+1];

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            dp[i][j] = INT_MAX;
            if(i==j){
                dp[i][j] = 0;
                continue;
            } 
            
            for(int x=1;x<j;x++){
                dp[i][j] = min(dp[i][j],dp[i][x]+dp[i][j-x]+1);
            }
            for(int y=1;y<i;y++){
                dp[i][j] = min(dp[i][j],dp[y][j]+dp[i-y][j]+1);
            }
            
        }
    }
    cout<<dp[a][b];
    return 0;
}


