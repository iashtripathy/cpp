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
        long long summ = 0;
        unordered_map<int,pair<int,int>>u;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(u.find(arr[i])!=u.end()){
                pair<int,int>p(i,u[arr[i]].second+1);
                u[arr[i]] = p;
            }
            else{
                pair<int,int>p(i,0);
                u[arr[i]] = p;
            }
            
            summ+=arr[i];
        }
        double mean = (double)summ/n;
        //cout<<mean<<endl;

        double req = summ - (mean*(n-2));
        //cout<<req<<endl;
        int cnt = 0;
/*         for(auto &x:u){
            cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
        }
        cout<<"----------------------"<<endl;
        for(auto &x:u){
            cout<<x.first<<" "<<x.second.first<<" "<<x.second.second;
            cout<<endl;
        }
        cout<<endl;*/
        for(int i=0;i<n-1;i++){
            double temp = req-arr[i];
            //cout<<"temp "<<req-arr[i]<<endl;
            if(abs(temp-int(temp))==0 && u.find(req-arr[i]) != u.end() && i<u[req-arr[i]].first){
                if(u[req-arr[i]].second>1){
                    cnt+=u[req-arr[i]].second;
                    --u[req-arr[i]].second;
                }
                else{

                    cnt+=1;
                }
                //cout<<"Inside"<<endl;
            }
        }
        cout<<cnt<<endl;
        //cout<<"--------"<<endl;
    }
    return 0;
}


