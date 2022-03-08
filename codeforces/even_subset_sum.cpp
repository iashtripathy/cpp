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
        int summ ;
        int start_index;
        bool flag = false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            start_index = i;
            summ = 0;
            for(int j=i;j<n;j++){
                summ+=arr[j];
                if(arr[j]%2==0){
                    cout<<"1"<<"\n";
                    cout<<j+1;
                    flag = true;
                    break;
                    
                }
                else if(summ%2==0){
                    cout<<j-i+1<<"\n";
                    for(int k=start_index;k<j+1;k++){
                        cout<<k+1<<" ";
                    }
                    flag = true;
                    break;
                }
            }
            if(flag==true) break;
        }
        if(flag==false) cout<<"-1";
        cout<<"\n";
    }

    return 0;
}