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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxx[n];
        maxx[0] = 1;
        int max_so_far = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>max_so_far){
                maxx[i] = maxx[i-1] + 1;
                max_so_far = arr[i];
            }
            else if(arr[i] == max_so_far){
                
                arr[i]+=1;
                maxx[i] = maxx[i-1] + 1;
                max_so_far = arr[i];
                
                
            }
            else{
                maxx[i] = maxx[i-1];
            }
        }
        cout<<maxx[n-1]<<"\n";
    }

    return 0;
}