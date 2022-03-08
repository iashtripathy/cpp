#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],vector<bool>& visited,int start){
    for(auto &node: adj[start]){
        if(visited[node]==false){
            visited[node] = true;
            dfs(adj,visited,node);
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

    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>final;
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            visited[i] = true;
            final.push_back(i);
            dfs(adj,visited,i);
        }
    }
    int ss = final.size();
    cout<<ss-1<<endl;
    if(ss>1){
        for(int i=1;i<ss;i++){
            cout<<final[0]<<" "<<final[i]<<endl;
        }
    }

    return 0;
}


