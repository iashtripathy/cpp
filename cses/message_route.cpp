/*
BFS solution to find the shortest distance between source and destination

Input : 
5 5
1 2
1 3
1 4
2 3
5 4

Output : 
3
1 4 5

*/


#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<int> adj[],vector<int>& pred,vector<int>& dist,int start,int end,int n){
    queue<int>q;
    vector<bool>visited(n+1,false);

    visited[start] = true;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto &node:adj[temp]){
            if(visited[node]==false){
                visited[node] = true;
                pred[node] = temp;
                dist[node] = dist[start] + 1;
                q.push(node);
                if(node==end) return true;
            }
        }
    }
    return false;
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
    vector<int>pred(n+1,-1);
    vector<int>dist(n+1,INT_MAX);

    int source = 1;
    int destination = n;
    if(!bfs(adj,pred,dist,source,destination,n)) cout<<"IMPOSSIBLE";
    else{
        //node points to end node
        int node = n;
        final.push_back(n);
        while(pred[node]!=-1){
            final.push_back(pred[node]);
            node = pred[node];
        }
        reverse(final.begin(),final.end());
        cout<<final.size()<<endl;
        for(auto &x:final) cout<<x<<" ";
    }


    return 0;
}


