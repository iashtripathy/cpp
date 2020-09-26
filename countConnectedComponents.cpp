/*
count connected components in undirected graph

input format:
8 5
1 2
2 3
2 4
3 5
6 7

Output:
3

Time complexity : O(V+E)
*/

#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> g[], int n,bool *visited,int start) {
    queue<int>q;
    q.push(start);
    visited[q.front()] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(const auto &x:g[temp]){
            if(visited[x]==false){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N+1];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        int count = 0;
        bool visited[N+1] = {false};
        for(int i=1;i<N+1;i++){
            if(visited[i]==false){
				++count;
                bfs(adj,N,visited,i);   
            }
        }
        cout << count;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/

