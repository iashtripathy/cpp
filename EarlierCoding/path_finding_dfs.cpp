/*
Finding a path from A to B.Here I have used DFS.
This solution guarantees a path if exist not necessarily the shortest path

Input
10 10
.#........
..........
..........
........#.
..........
..........
.........#
..........
.......AB.
.....#....

Output : 
YES
1
Any Path from A to B
*/


#include<bits/stdc++.h>
using namespace std;
/* L U R D*/
int x[4] = {0,-1,0,1};
int y[4] = {-1,0,1,0};
int cnt;
bool flag = false;
struct node{
    int i=0,j=0;
};
bool is_safe(int i,int j,vector<vector<bool>>& visited,vector<string>& grid,int m,int n){
    if(i>=0 && j>=0 && i<m && j<n && (grid[i][j]=='.' || grid[i][j]=='B') && visited[i][j]==false) return true;
    return false;
    
}
void dfs(vector<char>& directions,vector<string>& grid,vector<vector<bool>>& visited,int i,int j,int m,int n){
    for(int u=0;u<4;u++){
        int next_i = i + x[u];
        int next_j = j + y[u];
        if(is_safe(next_i,next_j,visited,grid,m,n) && !flag){
            visited[next_i][next_j] = true;
            if(u==0) directions.push_back('L');
            else if(u==1) directions.push_back('U');
            else if(u==2) directions.push_back('R');
            else if(u==3) directions.push_back('D');
            if(grid[next_i][next_j]=='B'){
                flag = true;
                //cout<<next_i<<" "<<next_j;
                return;
                
            }
            dfs(directions,grid,visited,next_i,next_j,m,n);
            //directions.pop_back();        
        }
    }
    
    
}
bool pathPresent(vector<char>& directions ,vector<string>& grid,int m,int n,struct node start,struct node end) {
/*     int m = grid.size();
    int n = grid[0].size(); */
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    //int cnt;
    //int max_cnt = 0;
    for(int i=start.i;i<m;i++){
        for(int j=start.j;j<n;j++){
            if(grid[i][j]=='A' && visited[i][j]==false){
                
                visited[i][j] = true;
                
                dfs(directions,grid,visited,i,j,m,n);
                if(flag==true) return true;
                //max_cnt = max(max_cnt,cnt);
            }
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int m,n;
    cin>>m>>n;
    vector<string> grid(m);
    vector<char>directions;
    struct node start,end;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                start.i = i;
                start.j = j;
            }
            if(grid[i][j]=='B'){
                end.i = i;
                end.j = j;
            }
        }
    }
/*     int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='.') ++res;

        }

    }
    cout<<res<<endl; */

    if(pathPresent(directions,grid,m,n,start,end)){
        cout<<"YES"<<endl<<directions.size()<<endl;
        for(auto &c:directions){
            cout<<c;
        }

    }
    else{
        cout<<"NO";
/*         for(auto &c:directions){
            cout<<c;
        } */
    }
    return 0;
}


