/*
Largest strongly connected component

Input
5 8
########
#..#...#
####.#.#
#..#...#
########

Output : 
8
*/


#include<bits/stdc++.h>
using namespace std;

int x[4] = {0,-1,0,1};
int y[4] = {-1,0,1,0};
int cnt;
bool is_safe(int i,int j,vector<vector<bool>>& visited,vector<string>& grid,int m,int n){
    if(i>=0 && j>=0 && i<m && j<n && grid[i][j]=='.' && visited[i][j]==false) return true;
    return false;
    
}
void dfs(vector<string>& grid,vector<vector<bool>>& visited,int *cnt,int i,int j,int m,int n){
    for(int u=0;u<4;u++){
        int next_i = i + x[u];
        int next_j = j + y[u];
        if(is_safe(next_i,next_j,visited,grid,m,n)){
            visited[next_i][next_j] = true;
            ++(*cnt);
            dfs(grid,visited,cnt,next_i,next_j,m,n);
            
        }
        
    }
}
int maxAreaOfIsland(vector<string>& grid,int m,int n) {
/*     int m = grid.size();
    int n = grid[0].size(); */
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    //int cnt;
    int max_cnt = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='.' && visited[i][j]==false){
                max_cnt++;
                cnt = 0;
                visited[i][j] = true;
                ++cnt;
                dfs(grid,visited,&cnt,i,j,m,n);
                
                //max_cnt = max(max_cnt,cnt);
            }
        }
    }
    return max_cnt;
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
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            
        }
    }
/*     int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='.') ++res;

        }

    }
    cout<<res<<endl; */
    cout<<maxAreaOfIsland(grid,m,n);
    return 0;
}


