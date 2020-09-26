/*

Example:
Input
2
6 6
5 0 5 2 2 3 4 0 4 1 1 3
3 4
3 0 1 0 2 0

Output:
1
1

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends



void dfs(vector<int>adj[],bool *visited,int start,stack<int>&s){
    for(auto x:adj[start]){
        if(visited[x]==false){
            dfs(adj,visited,x,s);    
        }
        
    }
    visited[start] = true;
    s.push(start);
}
vector<int> topoSort(int N, vector<int> adj[]) {
    // Your code here
    //int arr[N] = {0};
    vector<int>res;
    stack<int>s;
    bool visited[N] = {false};
    for(int i=0;i<N;i++){
        if(visited[i]==false){
            dfs(adj,visited,i,s);
        }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

