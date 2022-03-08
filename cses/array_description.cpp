#include<bits/stdc++.h>
using namespace std;
int ans = 0;

int find_count(vector<int>&arr,int begin,int n,int m,int prev,int ans){
    if(begin==-1) return 1; 
    if(begin==n-1){
        if(arr[begin]!=0){
            ans+=find_count(arr,begin-1,n,m,arr[begin],ans);
        }
        else{
            for(int i=1;i<=m;i++){
                arr[begin] = i;
                ans+=find_count(arr,begin-1,n,m,arr[begin],ans);
                arr[begin] = 0;
            }
        }
    } 
    else if(begin!=n-1){
        if(arr[begin]!=0){
            if(abs(prev-arr[begin])>1) return 0;
            else ans+=find_count(arr,begin-1,n,m,arr[begin],ans);
        }
        else{
            for(int i=1;i<=m;i++){
                if(abs(prev-i)<=1){
                    arr[begin] = i;
                    ans+=find_count(arr,begin-1,n,m,arr[begin],ans);
                    arr[begin] = 0;
                }

            }
        }
    }
    return ans;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int n,m;
    cin>>n>>m;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    find_count(arr,n-1,n,m,-1,0);
    cout<<ans;
    return 0;
}


