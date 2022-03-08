#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int n,x;
    cin>>n>>x;
    int price_book[n],pages_book[n];
    
    for(int i=0;i<n;i++){
        cin>>price_book[i];
    }

    for(int i=0;i<n;i++){
        cin>>pages_book[i];
    }
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        v.push_back({price_book[i],pages_book[i]});
    }
    sort(v.begin(),v.end());

    vector<vector<int>>res(n+1,vector<int>(x+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(i==0 || j==0) res[i][j] = 0;
            else{
                if(v[i-1][0] > j){
                    res[i][j] = res[i-1][j];
  
                }
                else{
                    res[i][j] = max(res[i-1][j],v[i-1][1]+res[i-1][j-v[i-1][0]]);
                }
            }
        }
    }

    cout<<res[n][x];


    return 0;
}


