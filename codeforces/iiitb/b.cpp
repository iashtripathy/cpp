#include<bits/stdc++.h>
using namespace std;
bool flag[1000] = {false};
void find_min(int n ,vector<int>&arr){
    int minn = INT_MAX;
    int index = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<minn && !flag[i]){
            minn = arr[i];
            index = i;
        }
    }
    flag[index] = true;
}
void find_max(int n ,vector<int>&arr){
    int maxx = INT_MIN;
    int index = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxx && !flag[i]){
            maxx = arr[i];
            index = i;
        }
    }
    flag[index] = true;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    if(n%2==0){
        for(int i=0;i<n-1;i++){
            if(i%2==0)
                find_min(n,arr);
            else
                find_max(n,arr);
        }
    }
    else{
        for(int i=0;i<n-1;i++){
            if(i%2==0)
                find_max(n,arr);
            else
                find_min(n,arr);
        }
    }
    for(int i=0;i<n;i++){
        if(!flag[i]){
            cout<<arr[i];
            break;
        }
    }
    return 0;
}


