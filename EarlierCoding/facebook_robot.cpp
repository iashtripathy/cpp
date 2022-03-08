
/*#include<bits/stdc++.h>
using namespace std;
int move_left(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited);
int move_right(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited);
int move_l_up(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited);
int move_r_up(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited);


int move_left(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited){
    if(x1==y1 && x2==y2) return cnt;
    if( (x1<0 && y2>=m) || x1<0 || y1>=m ){
        x1 = x1+1;
        y1 = y1-1;
        if(!visited[y1-1][x1+1]){
            visited[y1-1][x1+1] = true;
            return move_r_up(n,m,x1+1,y1-1,x2,y2,cnt,visited);
        }
        else{
            return -1;
        }
        
    }
    if(!visited[y1+1][x1-1]){
        visited[y1+1][x1-1] = true;
        return move_left(n,m,x1-1,y1+1,x2,y2,++cnt,visited);
    }
    else{
        return -1;
    }
    
}

int move_l_up(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited){
    if(x1==y1 && x2==y2) return cnt;
    if( (x1<0 && y2<0) || x1<0 || y1<0 ){
        x1 = x1+1;
        y1 = y1+1;
        if(!visited[y1+1][x1+1]){
            visited[y1+1][x1+1] = true;
            return move_right(n,m,x1+1,y1+1,x2,y2,cnt,visited);
        }
        else{
            return -1;
        }
        
    }
    if(!visited[y1-1][x1-1]){
        visited[y1-1][x1-1] = true;
        return move_l_up(n,m,x1-1,y1-1,x2,y2,++cnt,visited);
    }
    else{
        return -1;
    }
    
}

int move_r_up(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited){
    if(x1==y1 && x2==y2) return cnt;
    if( (x1>=m && y2<0) || x1>=m || y1<0 ){
        x1 = x1-1;
        y1 = y1+1;
        if(!visited[y1+1][x1-1]){
            visited[y1+1][x1-1] = true;
            return move_left(n,m,x1-1,y1+1,x2,y2,++cnt,visited);
        }
        else{
            return -1;
        }

    }
    if(!visited[y1-1][x1+1]){
        visited[y1-1][x1+1] = true;
        return move_r_up(n,m,x1+1,y1-1,x2,y2,++cnt,visited);
    }
    else{
        return -1;
    }
}

int move_right(int n,int m,int x1,int y1,int x2,int y2,int &cnt,vector<vector<bool>>&visited){
    if(x1==y1 && x2==y2) return cnt;
    if( (x1>=n && y1>=m) || x1>=n || y1>=m){
        x1 = x1-1;
        y1 = y1-1;
        if(!visited[y1-1][x1-1]){
            visited[y1-1][x1-1] = true;
            return move_l_up(n,m,x1-1,y1-1,x2,y2,cnt,visited);
        }
        else{
            return -1;
        }    
        
    }
    if(!visited[y1+1][x1+1]){
        visited[y1+1][x1+1] = true;
        return move_right(n,m,x1+1,y1+1,x2,y2,++cnt,visited);
    }
    else{
        return -1;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int cnt = 0;
    int n,m,x1,y1,x2,y2;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    
    vector<vector<bool>>visited(m+1,vector<bool>(n+1,false));
    visited[y1][x1] = true;
    int x = move_right(4,5,1,2,0,1,cnt,visited);
    if(x==-1) cout<<"-1";
    else cout<<cnt;
    return 0;
}

*/
