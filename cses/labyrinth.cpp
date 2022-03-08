/*


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
R
*/


#include<bits/stdc++.h>
using namespace std;
/* L U R D*/
int x[4] = {0,-1,0,1};
int y[4] = {-1,0,1,0};
int cnt;
bool flag = false;
const int maxX = 1005;
const int maxY = 1005;
char grid[maxX][maxY];
struct node{
    int i=0,j=0;
};
bool is_safe(int i,int j,vector<vector<bool>>& visited,int m,int n){
    if(i>=0 && j>=0 && i<m && j<n && (grid[i][j]=='.' || grid[i][j]=='B') && visited[i][j]==false) return true;
    return false;
    
}

bool pathPresent(vector<char>& directions ,vector<vector<int>>& dist,vector<vector<pair<int,int>>>& pred,int m,int n,struct node start,struct node end) {

    queue<node>q;
    //bool visited[m][n] = {false};
    vector<vector<bool>>visited(m,vector<bool>(n,false));

    visited[start.i][start.j] = true;
    q.push(start);
    dist[start.i][start.j] = 0;
    
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            node next_node;
            next_node.i = temp.i + x[k];
            next_node.j = temp.j + y[k];
            if(is_safe(next_node.i,next_node.j,visited,m,n)){
                //cout<<"Inside"<<endl;
                visited[next_node.i][next_node.j] = true;
                pred[next_node.i][next_node.j] = {temp.i,temp.j};
                //cout<<pred[8][8].first<<" "<<pred[8][8].second<<endl;
                dist[next_node.i][next_node.j] = dist[temp.i][temp.j] + 1;
                q.push(next_node);
                if(grid[next_node.i][next_node.j]=='B'){
                    //cout<<"Here I am!!---"<<grid[next_node.i][next_node.j]<<endl;
                    return true;
                } 
            }
        }
    }   
    return false;
}







int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //endif

    int m,n;
    cin>>m>>n;
    //vector<string> grid(m);
    
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

    vector<vector<pair<int,int>>>pred(m,vector<pair<int,int>>(n,{-1,-1}));
    
    vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

    vector<char>directions;
    vector<node>final;
    if(pathPresent(directions,dist,pred,m,n,start,end)){
        node temp = end;
        final.push_back(temp);
        node p;
        p.i = pred[temp.i][temp.j].first;
        p.j = pred[temp.i][temp.j].second;
        //cout<<"Here : "<<temp.i<<" "<<temp.j<<endl;
        cout<<"YES"<<endl;
        while(p.i!= -1 && p.j!= -1){
            
            //cout<<"Here";
            final.push_back(p);
            for(int k=0;k<4;k++){
                if(temp.i+x[k]==p.i && temp.j+y[k]==p.j){
                    if(k==0) directions.push_back('R');
                    else if(k==1) directions.push_back('D');
                    else if(k==2) directions.push_back('L');
                    else if(k==3) directions.push_back('U');
                    break;
                }
            }
            //cout<<p.i<<" "<<p.j<<endl;
            temp.i = p.i;
            temp.j = p.j;
            //cout<<pred[temp.i][temp.j].first<<" "<<pred[temp.i][temp.j].second<<endl;
            p.i = pred[temp.i][temp.j].first;
            p.j = pred[temp.i][temp.j].second;
            //cout<<"Here";
            //cout<<p.i<<" "<<p.j<<endl;
            
        }
        
        reverse(directions.begin(),directions.end());
        cout<<directions.size()<<endl;
        for(auto &x:directions) cout<<x;

    }
    else{
        cout<<"NO";
    }
    return 0;
}


