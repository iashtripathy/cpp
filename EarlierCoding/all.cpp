//adjacency list
#include<bits/stdc++.h>
using namespace std;
int main(){
    int edges,vertices;
    cin>>edges>>vertices;
    vector <int> v[vertices];
    int arr[2*edges];
    for(int i=0;i<(2*edges);i++){
        cin>>arr[i];
    }
    for(int i=0;i<(2*edges);i+=2){
        v[arr[i]].push_back(arr[i+1]);
    }
    for(int i=0;i<vertices;i++){
        for(const auto &j:v[i]){
            cout<<i<<"->"<<j<<endl;
        }
    }
    return 0;
}

//balanced paranthesis
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
    int T;
    cin>>T;
    while(T--){
        string expr;
        cin>>expr;
        stack<char>s;
        //cout<<expr;
        if(expr[0]==')' || expr[0]=='}' || expr[0]==']'){
            cout<<"not balanced";
            goto here;
        }
        //cout<<expr;
        s.push(expr[0]);
        for(int i = 1; i<expr.length(); i++){
            if(expr[i]=='{' || expr[i]=='[' || expr[i]=='('){
                s.push(expr[i]);
            }
            else{
                if(!s.empty()){
                    if(expr[i] == '}' and s.top() == '{'){
                        s.pop();    
                    }
                    else if(expr[i] == ']'  and s.top() == '['){
                        s.pop();
                    }
                    else if(expr[i] == ')' and s.top() == '('){
                        s.pop();
                    }
                    else{
                        cout<<"not balanced";
                        goto here;
                    }                    
                }
                else{
                    cout<<"not balanced";
                    goto here;
                }

            }
        }
        if(s.empty()==true){
            cout<<"balanced";
        }
        else{
            cout<<"not balanced";
        }
        here:
        cout<<endl;
        while(!s.empty()){
            s.pop();    
        }
        
    }
	return 0;
}

//bfs
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

//count connected components
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


//count disticnt elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    //int arr[] = {10,20,20,10,30,40,10};
    //int arr[] = {10,10,10,10};
    int arr[] = {73}; 
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    int count = 0;
    unordered_map <int,int> m;
    for(int i=0;i<size;i++){
        ++count;
        if(m.find(arr[i])!=m.end()){
            m[arr[i]]++;    
        }
        else{
            m.insert({arr[i],m[arr[i]]++});
        }
        
        /* for(auto &x:m){
            cout<<x.first<<" "<<x.second<<" and ";
        } 
        cout<<endl; */
        if(count>=k){
            cout<<"size: "<<m.size()<<" ";
            if(m[arr[count-k]]==1){
                m.erase(arr[count-k]);
            }
            else{
                m[arr[count-k]]--;
            }
            
        }
    }
    return 0;
}


//graph start and end times kosaraju
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


//indexSorting
#include<bits/stdc++.h>
//#include<iostream>
//#include<utility>
using namespace std;
int main(){
    int arr[4] = {20,40,30,10};
    vector <pair<int,int>> v;
    for(int i=0;i<4;i++){
        v.push_back({arr[i],i});
        //v.push_back(make_pair(arr[i],i));
    }   
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<","<<v[i].second<<endl;
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<","<<v[i].second<<endl;
    }    
    return 0;
}

//kosaraju connected components
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


//maximum of subarrays of size k
#include<bits/stdc++.h>
using namespace std;
int main(){
    //int arr[] = {10,8,5,12,15,7,6};
    int arr[] = {10,20,1,1,2,-3,5,5,30};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    deque <int> dq;

    for(int i=0;i<arrLen;i++){
        //count++;
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);

        if(dq.back()>=k-1){
            cout<<arr[dq.front()]<<endl;
            if(dq.back()-dq.front()==k-1){
                dq.pop_front();
            }          
        }
 

    }
    return 0 ;
}


//merge two sorted arrays
/*
O(m+n)log m solution where n is size of arr1 and m is size of arr2
*/
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    
	    //min heap
	    make_heap(arr1,arr1+n,greater<int>());
	    make_heap(arr2,arr2+m,greater<int>());
	    int i = 0;
	    int j = 0;
	    
	    while(i<n && j<m){
	        if(arr2[j]<arr1[i]){
	            int temp = arr1[i];
	            arr1[i] = arr2[j];
	            arr2[j] = temp;
	            pop_heap(arr2,arr2+m,greater<int>());

	            push_heap(arr2,arr2+m,greater<int>());

	        }
	        i++;
	    }
	    sort(arr2,arr2+m);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} 

//N queen
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v1;
vector<int>v2;
bool cmp(const vector<int>&a,const vector<int>&b){
    int i = 0;
    while(i!=a.size()){
        if(a[i]<b[i]){
            return 1;
        }
        else if(a[i]>b[i]){
            return 0;
        }
        else{
            i++;    
        }
        
    }   
}
bool issafe(int *arr[],int n,int x,int y){
    if(x==n-1 && y==n-1){
        return 1;
    }
    else{
        for(int i=x+1,j=y+1;i<n,j<n;i++,j++){
            if(i<n && j<n && arr[i][j]==1){
                return 0;
            }
        }
        for(int j=y+1;j<n;j++){
            if(j<n && arr[x][j]==1){
                return 0;
            }
        }
        for(int i=x-1,j=y+1;i>=0,j<n;i--,j++){
            if(i>=0 && j<n && arr[i][j]==1){
                return 0;
            }
        }
    }
    return 1;
}
void printSolution(int *arr[],int n){
    //cout<<"[";
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(arr[i][j]==1){
                //cout<<j+1<<" ";
                v2.push_back(j+1);
            }
        }
                    //cout<<endl;
    }
    v1.push_back(v2);
    v2.clear();
    //cout<<"]";
}

bool nqueen(int *arr[],int n,int y){
    bool res = false;
    if(y<0){
        printSolution(arr,n);
        return 1;
    }
    for(int x=n-1;x>=0;x--){
        if(issafe(arr,n,x,y)){
                arr[x][y] = 1;
                //the below code in comments would be correct if the he asked is there a solution or not because if there is a solution then we return 1 and donnot check any further
                /*if(nqueen(arr,n,x,y-1)){
                    //print(matrix 

                    return 1;
                }*/
                // even if we have one solution our res should be true hence we do or operation
                res = nqueen(arr,n,y-1) || res;
                arr[x][y] = 0;
        }
    }
    return res;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    //int arr[11][11];
	    int *arr[n];
	    for(int i=0;i<n;i++){
	        arr[i] = (int *)calloc(n,sizeof(int));
	    }
	    //int arr[n][n] = {0};
	    //for(int x=n-1;x>=0;x--){
    	    if(!(nqueen(arr,n,n-1))){
    	        cout<<"-1";
    	    }
    	    else{
    	        sort(v1.begin(),v1.end(),cmp);
    	        
                for(int i=0;i<v1.size();i++){
                    cout<<"[";
                    for(auto x:v1[i]){
                        cout<<x<<" ";
                    }
                    cout<<"] ";
                }
                //cout<<"]";
    	    }
	    //}
        v1.clear();
	    cout<<endl;
	}
	return 0;
}


//priority queue
// CPP code to illustrate// priorit_queue and its// various function
#include<bits/stdc++.h>
using namespace std; 
struct Person {    
    int age;    
    float ht;        
    Person(int a, float h){        
        age = a;        
        ht = h;    
    }
}; 
struct myCmp {    
    bool operator()(Person const &p1, Person const &p2){        
        return p1.ht < p2.ht;    
    }
};

// Drivers Method

int main(){     
   // Creating a priority queue    
   priority_queue < Person, vector<Person>, myCmp> pq;     
   // Pushing elements into    // the priority_queue    
   // First Person    
   Person p1(21, 5);    
   pq.push(p1);        
   // Second Person    
   Person p2(22, 6);    
   pq.push(p2);        
   // Third Person    
   Person p3(23, 7);    
   pq.push(p3);     
   // Displaying the top elements    // of the queue    
   while (pq.empty() == false) {        
       cout<<pq.top().ht << " ";        
       pq.pop();    
   }    
   return 0;
}


//simple string
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>k;
    
        string str;
        cin>>str;
        //getline(cin,str);

        stack <char> s;
        char ch;
        
        for(int i=0;i<str.length();i++){
        
            s.push(str[i]);
            while(k!=0 && s.size()>1){
                ch = s.top();
                s.pop();
                if(ch!=s.top()){
                    s.pop();
                    s.push('*');
                    k--;
                }
                else{
                    s.push(ch);
                    break;
                }
            }
        }
        cout<<s.size()<<"\n";
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    return 0;
}


//sudoku
#include <iostream>
#include<bits/stdc++.h>
# define n 9
using namespace std;

bool isSafe(int *matrix[],int x,int y,int value){
    //for row
    for(int j=0;j<n;j++){
        if(matrix[x][j]==value){
            return false;
        }
    }
    //for column
    for(int i=0;i<n;i++){
        if(matrix[i][y]==value){
            return false;
        }
    }
    //for subgrid
    int subGridSize = sqrt(n);
    int startX = x - (x%subGridSize);
    int startY = y - (y%subGridSize);
    for(int i = startX;i<subGridSize+startX;i++){
        for(int j = startY;j<subGridSize+startY;j++){
            if(matrix[i][j]==value){
                return false;
            }
        }
    }
    return true;
}
bool solve(int *matrix[]){
    int i,j;

    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(matrix[x][y]==0){
                i = x;
                j = y;
                goto here;
                //break;
            }
            else{
                if(x==n-1 && y==n-1){
                    return true;
                }
            }
        }
    }
    /*if(i==9){
        return true;
    }*/
    here:
    //cout<<"\ni= "<<i<<" j= "<<j<<endl;
    for(int value=1;value<=n;value++){
        if(isSafe(matrix,i,j,value)){
            matrix[i][j] = value;
            /*if(i==n-1 && j==n-1){
                return true;
            }*/
            if(solve(matrix)){
                return true;    
            }
            matrix[i][j] = 0;
        }    
    }
    return false;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int *matrix[n];
	    for(int i=0;i<n;i++){
	        matrix[i] = (int *)calloc(n,sizeof(int));
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>matrix[i][j];
	        }
	    }
	    if(solve(matrix)){
	        for(int i =0;i<n;i++){
	            for(int j=0;j<n;j++){
	                cout<<matrix[i][j]<<" ";
	            }
	            //cout<<endl;
	        }
	    }
	    cout<<endl;
	    for (int i = 0; i < n; i++){
            int *currentIntPtr = matrix[i];
            free(currentIntPtr);
        }
	}
	return 0;
}


//task scheduling
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool mycmp(pair<long long int,char>p1,pair<long long int,char>p2){
    //if both has same time then the one with Arrival time has to be put first in the sorted order
    if(p1.first==p2.first){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main() {
	//code
	long long int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int enter[n];
	    long long int exitt[n];
	    for(long long int i = 0;i<n;i++){
	        cin>>enter[i];
	    }
	    for(long long int i = 0;i<n;i++){
	        cin>>exitt[i];
	    }

	    vector<pair<long long int,char>> v;
	    
	    for(long long int i =0;i<n;i++){
	        v.push_back({enter[i],'A'});
	    }
	    for(long long int i =0;i<n;i++){
	        v.push_back({exitt[i],'D'});
	    }
	    sort(v.begin(),v.end(),mycmp);
	    long long int cur = 0,ans=0,t=0;
	    for(auto &x:v){
	        if(x.second=='A'){
	            cur = cur + 1;
	        }
	        else if(x.second=='D'){
	            cur = cur - 1;
	        }
	        if(cur>ans){
	            ans = cur;
	            t = x.first;
	        }
	    }
	    cout<<ans<<" "<<t<<endl;
	}
	return 0;
}


//topological sort
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


//vertical sum
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector<int> verticalSum(Node *root);
int main() 
{
    
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        vector <int> res = verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
void sum(Node *root,int count,map<int,int>&u) {
    // add code here.
    if(root == NULL){
        return;
    }
    if(root != NULL){
        //u.insert({count,(u.at(count)+root->data)});
        u[count] += root->data;
        if(root->left){
            sum(root->left,count-1,u);
        }
        if(root->right){
            //count++;
            sum(root->right,count+1,u);
        }
    }
}
vector <int> verticalSum(Node *root) {
    int count = 0;
    map<int,int>u;
    vector<int>v;
    if(root == NULL){
        v.push_back(0);
        return v;
    }
    else{
        sum(root,count,u);
    }
    for(auto &x:u){
        //cout<<x.first<<" "<<x.seconf
        v.push_back(x.second);
    }
    return v;
}


//width of the tree
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int getMaxWidth(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);
        
        cout << getMaxWidth(root) <<endl;
    }
    return 0;
}


// } Driver Code Ends


/*  Structure of a Binary Tree 

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

int getwidth(Node* root,queue<pair<struct Node*,int>>&q,int level){
    int res = 0;
    int maxWidth = 1;
    int value = 1;
    while(!q.empty()){
        pair<struct Node*,int> p = q.front();
        if(p.second!=value){
            //maxwidth = max(maxWidth,res);
            res =  0;
        }
        q.pop();
        value = p.second;
        if((p.first)->left){
            q.push({(p.first)->left,p.second+1});
            res++;            
        }
        if((p.first)->right){
            q.push({(p.first)->right,p.second+1});
            res ++;
        }

        
        maxWidth = max(res,maxWidth);
    }
    
    return maxWidth;
} 

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(root==NULL){
        return -1;
    }
    else{
        queue<pair<struct Node*,int>>q;
        int level = 1;
        q.push({root,level});
        return getwidth(root,q,level);
    }
   // Your code here
}