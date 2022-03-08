#include<bits/stdc++.h>
using namespace std;
#define max 200000
int sol[max] = {0};
void dfs(vector<int>adj[],int curr,int par){
    for(auto &x:adj[curr]){
        if(x!=par){
            dfs(adj,x,curr);
            sol[curr]=sol[curr]+1+sol[x];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //endif

    int n;
    cin>>n;
    
    vector<int>adj[n+1];
    for(int i=2;i<n+1;i++){
        int p;
        cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs(adj,1,-1);
    for(int i=1;i<=n;i++){
        cout<<sol[i]<<" ";
    }
    return 0;
}


