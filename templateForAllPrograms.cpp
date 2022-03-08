#include<bits/stdc++.h>
using namespace std;


//Factors of a number  =>  For example, 12 = 2 2 · 3, so the result of the function is [2, 2, 3].
vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) {
        f.push_back(n);
    }
    return f;
}

/*-----------------------------------------End Here------------------------------------------------*/


//Modular Exponentiation
int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

/*-----------------------------------------End Here------------------------------------------------*/


//Longest Common subsequence
int lcs(int m, int n, string s1, string s2)
{
    // your code here
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

/*-----------------------------------------End Here------------------------------------------------*/



//Longest Common Substring
int longestCommonSubstr (string s1, string s2, int m, int n)
{
    // your code here
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;          
        }
    }
    int maxx = INT_MIN;     //This stores the max length substring
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if( (i==1 || j==1) && s1[i-1]==s2[j-1] ){
                dp[i][j] = 1 ;                //If the 1st character matches then count = 1
            }
            else if(s1[i-1]==s2[j-1]){
                if(s1[i-2]==s2[j-2]){
                    dp[i][j] = 1 + dp[i-1][j-1];      //If consequtive characters matches then only increment count
                }
                else{
                    dp[i][j] = 1;                     //If adjacent characters doesnt match it means it is starting then count = 1
                }
                
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);   //If characters doesnt match 
            }
            maxx = max(dp[i][j],maxx);                     //final answers is held by this
        }
    }
    return maxx;
}

/*-----------------------------------------End Here------------------------------------------------*/




//Length of longest increasing subsequence;
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,1);             //dp[i] indicates length of longest increasing subsequence ending with i
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i] = max(dp[i],1+dp[j]);      //for every index i start j from 0 and keep on checking nums[j]<nums[i].
            }
        }
    }
    int maxx = INT_MIN;
    for(int i=0;i<n;i++){
        maxx = max(maxx,dp[i]);
    }
    return maxx;
}


/*-----------------------------------------End Here------------------------------------------------*/



/*lis with difference d .the successive arithmatic sequence should come one after the other.
Eg :    [0,-3,2,3,4]      K = 3
Output = 2 i.e : ([0,3])
*/ 
int longestSubsequence(vector<int>& arr, int d) {
  int n = arr.size();
  map <int,int> m;
  int ans = 0;
  for(int i =0;i<n;i++){
     int x = arr[i];
     m[x] = 1 + (m[x-d]);
     ans = max(ans,m[x]);
  }
  return ans;
}

/*-----------------------------------------End Here------------------------------------------------*/


/*
Longest increasing subsequence with difference k for i<j if we have arr[i]>arr[j] we should also consider this.
Eg :    [0,-3,2,3,4]      K = 3
Output = 3 i.e : ([-3,0,3])
Time Complexity : O(n)               Space Complexity : O(n)

*/
int longestIncreasingSubsequence(vector<int>& arr, int k) {
  int n = arr.size();  
  if(n==0){
      return 0;                             //empty array
  }
  unordered_map <int,int> um;
  for(int i=0;i<n;i++){
      if(um.find(arr[i])==um.end()){
          um[arr[i]] = 0;                         //Insert all elements into hashmap if they are not present and make their value = 0
      }
  }
  int count,maxx = INT_MIN,start=arr[0];
  for(int i=0;i<n;i++){
      count = 1;
      if(um[arr[i]]!=1){
          start = arr[i];
          while(um.find(start)!=um.end() && um[start]!=1){  //If the current element is not yet visited find the start of the subsequence
              start = start - k;            
          }     
          start = start + k;                                //point start to the starting of the subsequence element value
          um[start] = 1;                                    //mark the start of subsequence as visited which means its value = 1
          start = start + k;                                //point start to the next element of the subsequence
          while(um.find(start)!=um.end()){
              um[start] = 1;   //visited
              ++count;                                     //count result
              start = start + k;
          }
          
      }
      maxx = max(maxx,count);                               //Holds the max increasing subsequence
  }
  return maxx; 
}

/*-----------------------------------------End Here------------------------------------------------*/



//Edit distance.Find min number of operations required to equal both strings
int editDistance(string s, string t) {
    // Code here
    int m = s.size(),n=t.size();
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i] = i;        //if s1.size() == 0 then return length of s2;
    }
    for(int j=0;j<=m;j++){
        dp[j][0] = j;       //if s2.size() == 0 then return length of s1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+ min ( {dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]} );
            }
        }
    }
    return dp[m][n];
} 

/*-----------------------------------------End Here------------------------------------------------*/




//Detect Cycle in undirected graph
bool dfs(int v,int i, vector<int>adj[], vector<pair<char,int>> &visited){
    for(auto &x:adj[i]){
        
        if(visited[x].first=='W'){
            visited[x].first = 'G';
            visited[x].second = visited[i].second + 1;
        
            if(dfs(v,x,adj,visited)){
        
                return true;
            };
            visited[x].first = 'B';
        }
        else if(visited[x].first=='G' && (i==x || abs(visited[i].second-visited[x].second)!=1)){    
            //i==x means self edge,
            //abs(....) means directly connected adge between two nodes isnt considered as cycle since it is an undirected graph
            return true;
        }
    }
    return false;
}


bool isCycle(int V, vector<int>adj[])     //from main function call this function
{
    vector <pair<char,int>> visited(V,{'W',0});
    for(int i=0;i<V;i++){
        
        if(visited[i].first=='W'){
            ++visited[i].second;
            visited[i].first = 'G';	            
            if(dfs(V,i,adj,visited)){
        
                return true;
            };
            visited[i].first = 'B';
        }
    }
    return false;
    // Code here
}

/*-----------------------------------------End Here------------------------------------------------*/


// BFS
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


/*-----------------------------------------------------End Here----------------------------------------------------*/


//Kosaraju Algorithm
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

int kosaraju(int V, vector<int> adj[])     //call this function from main
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

/*-----------------------------------------------------End Here----------------------------------------------------*/


//String compression   Eg : arr = ["a","a","b","b","c","c","c"]     Ans : ["a","2","b","2","c","3"]     Eg:2 : arr = ["a","b","b"] Ans: ["a",b","2"]
int compress(vector<char>& arr) {
    int n = arr.size();
    int j ,count=1;
    vector<char>ch;
    int i;
    for(i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            ++count;
        }
        else{
            ch.push_back(arr[i-1]);
            if(count>1){
                
                string s = to_string(count);
                for(int i=0;i<s.size();i++){
                    ch.push_back(s[i]);
                }                    
            }
            
            //arr[j] = to_string(count);
            //j+=2;
            count = 1;
        }
    }
    ch.push_back(arr[i-1]);
    if(count>1){
        
        string s = to_string(count);
        for(int i=0;i<s.size();i++){
            ch.push_back(s[i]);
        }    
    }
    
    //arr.clear();
    for(int j=0;j<ch.size();j++){
        //cout<<x<<" ";
        arr[j] = ch[j];
    }
    return ch.size();
}

/*-----------------------------------------------------End Here----------------------------------------------------*/

int main(){
    return 0;
}