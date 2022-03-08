#include<bits/stdc++.h>
using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //endif

    long long n;
    cin>>n;
    vector<long long> arr;
    long long maxx = INT_MIN;
    long long summ = 0;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        maxx = max(maxx,a);
        summ+=a;
        arr.push_back(a);
    }

    cout<<max(summ,2*maxx);
        
    
    return 0;
}


