/* #include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9 + 7)
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int n;
    cin>>n;
    int prod = n*(1+n);
    if(prod%4) cout<<"0";
    else{
        int half = prod/4;
        cout<<half<<endl;
        //int dp[n+1][half+1];
        vector<vector<int>>dp(n+1,vector<int>(half+1,0));
        //memset(dp,0,sizeof dp);

        for(int i=0;i<=n;i++){
            for(int j=0;j<=half;j++){
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else{
                    if(i>j) dp[i][j] = dp[i-1][j];
                    else{
                        dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%mod;
                    }
                }
            }
        }

        cout<<dp[n][half]/2;        
    }

    return 0;
}


*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  int target = n*(n+1)/2;
  if (target%2) {
    cout << 0 << endl;
    return 0;
  }
  target /= 2;

  vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
	(dp[i][j] += dp[i-1][left]) %= mod;
      }
    }
  }
  cout << dp[n-1][target] << endl;
}