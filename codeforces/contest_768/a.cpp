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
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector<int>s1;
        vector<int>s2;
        for(int i=0;i<n;i++){
            s1.push_back(a[i]);
            s2.push_back(b[i]);
        }
        sort(s1.begin(),s1.end(),greater<int>());
        sort(s2.begin(),s2.end(),greater<int>());
        int flag = 0;
        int max_1;
        //cout<<*(s1.begin())<<endl<<endl;
        if(s1[0]>s2[0]){
            flag = 1;
            max_1 = s1[0];
        }
        else {
            flag = 2;
            max_1 = s2[0];
        }
        int max_2 = INT_MIN;
        //cout<<"max_1 :"<<max_1<<endl;
        if(flag==1){
            for(int i=0;i<n;i++){
                if(b[i]>a[i]) max_2 = max(max_2,a[i]);
                else max_2 = max(max_2,b[i]);
            }
        }
        else if(flag==2){
            for(int i=0;i<n;i++){
                if(a[i]>b[i]) max_2 = max(max_2,b[i]);
                else max_2 = max(max_2,a[i]);
            }
        }
        cout<<max_1*max_2<<endl;
    }

    return 0;
}


