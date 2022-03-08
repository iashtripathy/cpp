#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        int start = 0;
        int search_for;
        int flag = 0;
        int minn = INT_MAX,index = 0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr[i] = a;
            if(flag==0 && arr[i]==i+1){
                start = i+1;
                continue;
            }
            else if(flag==0){
                start = i;
                search_for = i+1;
                flag = 1; 
            }
            if(arr[i]==search_for){
                index = i;
            }
        }
        reverse(arr.begin()+start,arr.begin()+(index+1));
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


