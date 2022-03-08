#include<bits/stdc++.h>
using namespace std;

int bfs(vector <int> adj[],int n,int x){
    bool visited[n] = {false};

    queue<int>q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(adj[temp].size()<2){
            adj[temp].push_back(n);
            return 0;
        }
        else{
            for(auto &x:adj[temp]){
                if(visited[x]==false){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }

    }
    return 0;
}


void dfs(int start,int arr[],vector<int>adj[],vector<int>&res,bool *visited){
    for(auto &x:adj[start]){
        if(visited[x]==false){
            visited[x] = true;
            dfs(x,arr,adj,res,visited);        
        }
        
        if(adj[x].size()!=0){
            int temp = 0;
            for(auto &i:adj[x]){
                temp+=arr[i];
            }
        
            arr[x] += temp; 
        
            res[x] = arr[x];
        }
        else{
            res[x] = arr[x];
        }
         
    }



}
int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    
    int n,x;
    cin>>n>>x;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr[n] = x;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    int p = bfs(adj,n,x);

    bool visited[n+1] = {false};
    vector<int>res(n+1,0);
    dfs(0,arr,adj,res,visited);
    for(auto &x:adj[0]){
        res[0]+=x;
    }
    long long finall = 0;
    for(int i=0;i<n+1;i++){
        cout<<res[i]<<" ";
        finall+=res[i];
    }

    cout<<"\n"<<finall;
    return 0;
}