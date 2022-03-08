// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfs(int v,vector<int>adj[],int i,bool *visited,int *startTime,int *endTime,int &count,stack<int>&s){
    for(const auto &x:adj[i]){
        if(visited[x]==false){
            visited[x] = true;
            startTime[x] = ++count;
            dfs(v,adj,x,visited,startTime,endTime,count,s);  
            endTime[x] = ++count;
            s.push(x);
        }
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code heree
    bool visited[V] = {false};
    int startTime[V] = {0};
    int endTime[V] = {0};
    int count = 0;
    stack<int>s;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            visited[i] = true;
            startTime[i] = count;
            dfs(V,adj,i,visited,startTime,endTime,count,s);
            endTime[i] = ++count;
            s.push(i);
        }
    }
    //int res = dfs(V,adj);
    
    for(int i=0;i<V;i++){
        cout<<startTime[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<endTime[i]<<" ";
    }
    return 0;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends