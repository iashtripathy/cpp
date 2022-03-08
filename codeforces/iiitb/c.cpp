#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int n,k;
    cin>>n>>k;
    vector<int>arr;
    //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
        //pq.push({temp,i});
    }
    long long summ = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<0 && k){
            arr[i] = -1*arr[i];
            //summ+=arr[i];
            k--;
        }
        summ+=arr[i];
    }
    if(k%2!=0){
        int minn = INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<minn) minn=arr[i];
        }
        summ = summ - (2*minn);
    }
    /*
    while(k && !pq.empty()){
        pair<int,int>t = pq.top();
        if(t.first<0){
            arr[t.second] = -1*arr[t.second];
            k--;
        }
        pq.pop();
    }
    long long summ = 0;
    for(int i=0;i<n;i++){
        summ+=arr[i];
        //cout<<arr[i]<<" ";
    }*/
    cout<<summ;
    return 0;
}


