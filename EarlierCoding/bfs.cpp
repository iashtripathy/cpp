/*
This code doesnt takes care of the case if the graph is disconnected
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        /*
        for disconnted graoh use the below code
        vector<int>res;  //to store the result
        bool visited[i] = {false};
        for(int i=0;i<N;i++){
            if(visited[i]==false{
                bfs(adj,N,res,visited);   //accept res and visited in bfs function as reference ie:&res,&visited
            })
        }
        */
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int n) {
    // Your code here
    vector<int>order;
    bool visited[n] = {false}; 
    queue<int>q;
    q.push(0);
    visited[q.front()] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        order.push_back(temp);
        for(const auto &x:g[temp]){
            if(visited[x]==false){
                q.push(x);
                visited[x] = true;
            }
        }
    }
    return order;
}