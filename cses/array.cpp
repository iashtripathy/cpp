#include<bits/stdc++.h>
using namespace std;
#define M (int) (1e9 + 7)
int find_count(vector<int>&arr,int n,int m){
    int dp[n+2][m+2];
    memset(dp,0,sizeof dp);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1){
                if(arr[i-1]==0 || arr[i-1]==j) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else if(arr[i-1]==0 || arr[i-1]==j)
                dp[i][j] = ((dp[i-1][j]+dp[i-1][j-1])%M + dp[i-1][j+1])%M;
            else dp[i][j] = 0;
        }
    }
    for(int i=1;i<=m;i++){
        ans = (ans + dp[n][i])%M;
    }

    
    return ans;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //endif

    int n,m;
    cin>>n>>m;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<find_count(arr,n,m);
    
    return 0;
}
