#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      string s;
      cin>>s;
      int k = n-4;
      string temp;
      bool flag = false;
      for(int i=0;i<=n-k;i++){
          temp = "";
          for(int x=0;x<i;x++){
              temp+=s[x];
          }
          for(int j = k+i;j<n;j++){
              temp+=s[j];
          }
          //cout<<<<" ";
          if(temp=="2020"){
              flag = true;
              break;
          }
      }
      if(flag==true){
          cout<<"YES"<<"\n";
      }
      else{
          cout<<"NO"<<"\n";
      }
      
    }

    return 0;
}