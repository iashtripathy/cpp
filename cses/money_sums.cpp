#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //endif

    int n;
    cin>>n;
    int arr[n];
    int summ = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        summ+=arr[i];
    }
    sort(arr,arr+n);
    
    int dp[n+1][summ+1];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;

    for(int j=1;j<=n;j++){
        dp[j][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=summ;j++){
            if(arr[i-1]<=j) dp[i][j] = max(dp[i-1][j] , dp[i-1][j-arr[i-1]]);
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    //cout<<endl;

    int cnt = 0;
    for(int i=1;i<=summ;i++){
        if(dp[n][i]==1) cnt+=1;
    }

    cout<<cnt<<endl;
    for(int i=1;i<=summ;i++){
        if(dp[n][i]==1) cout<<i<<" ";
    }
    return 0;
}


