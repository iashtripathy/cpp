// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfs(int v,vector<int>adj[],int i,bool *visited,stack<int>&s){
    for(const auto &x:adj[i]){
        if(visited[x]==false){
            visited[x] = true;
            dfs(v,adj,x,visited,s);  
            s.push(x);
        }
    }
}

void dfs1(int v,vector<int>adj[],int i,bool *visited){
    for(const auto &x:adj[i]){
        if(visited[x]==false){
            visited[x] = true;
            dfs1(v,adj,x,visited);  
        }
    } 
}

int kosaraju(int V, vector<int> adj[])
{
    
    // First time applying dfs To find the completion order of vertices 
    bool visited[V] = {false};

    stack<int>s;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            visited[i] = true;
            dfs(V,adj,i,visited,s);
            s.push(i);
        }
    }
   

    //reversing the edges of the graph
    vector <int> newAdj[V];
    for(int i=0;i<V;i++){
        for(auto &x:adj[i]){
            newAdj[x].push_back(i);
        }
    }
    
    //applying the dfs1 second time
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    //visited[V] = {false};
    int count = 0;
    while(!s.empty()){
        int i = s.top();
        s.pop();
        if(visited[i]==false){
            visited[i] = true;
            ++count;
            dfs1(V,newAdj,i,visited);
        }
    }
    return count;
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