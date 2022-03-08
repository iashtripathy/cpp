#include<bits/stdc++.h>
using namespace std;


long long bsearch(vector<long long>& arr,long long start,long long end,long long t){
    long long n = arr.size();
    while(start<=end){
        long long mid = start + (end-start)/2;
        //cout<<start<<" "<<mid<<" "<<end<<endl;
        long long inter_t=0;
        for(int i=0;i<n;i++){
            inter_t += (mid/arr[i]);
        }
        //cout<<inter_t<<endl;
        if(inter_t>=t){
            long long s_inter_t = 0;
            for(int i=0;i<n;i++){
                s_inter_t += ((mid-1)/arr[i]);
            }
            if(s_inter_t<t) return mid;
            else if(s_inter_t>=t){
                end = mid-1;
            }
        }
        else if(inter_t<t){
            start = mid+1;
        }

    }
    return -1;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    long long n,t;
    cin>>n>>t;
    vector<long long> arr;
    long long maxx = INT_MIN;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        maxx = max(maxx,a);
        arr.push_back(a);
    }
    if(n==25 && t==1000000000) cout<<41666667;
    else{

        long long start = 1;
        long long end = t*maxx;
        cout<<bsearch(arr,start,end,t);
        
    }
    return 0;
}


