// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(vector<vector<int>> &m, int n,vector<string> &v,vector<vector<int>> &visited,int i,int j,stack<char>&s){
        if(i==n-1 && j==n-1){
            string str;
            while(!s.empty()){
                str = str+s.top();
                s.pop();
            }
            reverse(str.begin(), str.end());            
            v.push_back(str);
            for(auto &x:str){
                s.push(x);
            }

        }
        else{
            if(i==0 && j==0){
                if(m[i+1][j] && visited[i+1][j]==0){
                    visited[i+1][j] = 1;
                    s.push('D');
                    dfs(m,n,v,visited,i+1,j,s);
                    visited[i+1][j] = 0;
                    s.pop();
                    
                }
                if(m[i][j+1] && visited[i][j+1]==0){
                    visited[i][j+1] = 1;
                    s.push('R');
                    dfs(m,n,v,visited,i,j+1,s);
                    visited[i][j+1] = 0;
                    s.pop();
                }
            }
            else if(i==0 && j!=0){
                if(m[i+1][j] && visited[i+1][j]==0){
                    visited[i+1][j] = 1;
                    s.push('D');
                    dfs(m,n,v,visited,i+1,j,s);
                    visited[i+1][j] = 0;
                    s.pop();
                }
                if(j+1 < n && m[i][j+1] && visited[i][j+1]==0){
                    visited[i][j+1] = 1;
                    s.push('R');
                    dfs(m,n,v,visited,i,j+1,s);
                    visited[i][j+1] = 0;
                    s.pop();
                }
                if(m[i][j-1] && visited[i][j-1]==0){
                    visited[i][j-1] = 1;
                    s.push('L');
                    dfs(m,n,v,visited,i,j-1,s);
                    visited[i][j-1] = 0;
                    s.pop();
                }
            }
            else if(i!=0 && j==0){
                if(m[i-1][j] && visited[i-1][j]==0){
                    visited[i-1][j] = 1;
                    s.push('U');
                    dfs(m,n,v,visited,i-1,j,s);
                    visited[i-1][j] = 0;
                    s.pop();
                }
                if(j+1<n && m[i][j+1] && visited[i][j+1]==0){
                    visited[i][j+1] = 1;
                    s.push('R');
                    dfs(m,n,v,visited,i,j+1,s);
                    visited[i][j+1] = 0;
                    s.pop();
                }
                if(i+1<n && m[i+1][j] && visited[i+1][j]==0){
                    visited[i+1][j] = 1;
                    s.push('D');
                    dfs(m,n,v,visited,i+1,j,s);
                    visited[i+1][j] = 0;
                    s.pop();
                }
                
            }
            else if(i!=0 && j!=0){
                if(m[i-1][j] && visited[i-1][j]==0){
                    visited[i-1][j] = 1;
                    s.push('U');
                    dfs(m,n,v,visited,i-1,j,s);
                    visited[i-1][j] = 0;
                    s.pop();
                }
                if(j+1  < n && m[i][j+1] && visited[i][j+1]==0){
                    visited[i][j+1] = 1;
                    s.push('R');
                    dfs(m,n,v,visited,i,j+1,s);
                    visited[i][j+1] = 0;
                    s.pop();
                }
                if(m[i][j-1] && visited[i][j-1]==0){
                    visited[i][j-1] = 1;
                    s.push('L');
                    dfs(m,n,v,visited,i,j-1,s);
                    visited[i][j-1] = 0;
                    s.pop();
                }
                if(i+1 < n && m[i+1][j] && visited[i+1][j]==0){
                    visited[i+1][j] = 1;
                    s.push('D');
                    dfs(m,n,v,visited,i+1,j,s);
                    visited[i+1][j] = 0;
                    s.pop();
                }
            }            
        }

        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector <string> v;
        vector <vector<int>> visited;
        for(int i=0;i<m.size();i++){
            vector <int> temp;
            for(int j=0;j<m[0].size();j++){
                temp.push_back(0);
            }
            visited.push_back(temp);
        }
        stack <char> s;
        if(m[0][0]==1){
            visited[0][0] = 1;
            dfs(m,n,v,visited,0,0,s);
            visited[0][0] = 0;
                
        }
        sort(v.begin(),v.end());
        return v;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends