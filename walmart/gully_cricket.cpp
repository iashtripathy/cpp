#include<bits/stdc++.h>
using namespace std;
string solve(int N,vector<vector<string>>info){
    //cout<<N<<"\n";
    int i= 1;
    int cnt = 0;
    unordered_map<string,int>u;
    u.insert({"W",1});
    u.insert({"WD",1});
    u.insert({"0",1});
    u.insert({"1",1});
    u.insert({"2",1});
    u.insert({"3",1});
    u.insert({"4",1});
    u.insert({"5",1});
    u.insert({"6",1});
    
    unordered_map<string,int>um;

    /*for(int i=0;i<info.size();i++){
   
            cout<<info[i][0]<<" "<<info[i][1];          
   
        cout<<endl;
    }*/
    int k = 0;
    while(info[k][1]=="WD"){
        k++;
    }
    if(u.find(info[k][1])!=u.end()) cnt = 1;
    bool flag =true;
    
    um.insert({info[0][0],1});
    while(i<info.size()){
        //cout<<i<<" ";
        if(um.find(info[i][0])==um.end()){
            um.insert({info[i][0],1});
        }
        
        if(um.size()>5){
            flag = false;
            //cout<<"flag > 5";
            break;
        }
        if(cnt<6){
            if(info[i-1][0]==info[i][0] && u.find(info[i][1])!=u.end() && info[i][1]!="WD") ++cnt;
            else if(info[i-1][0]==info[i][0] && u.find(info[i][1])!=u.end() && info[i][1]=="WD") cnt=cnt;
            else if(cnt==0 && info[i][1]=="WD") cnt=cnt;
            else {
                flag = false;
                //cout<<"flag < 6"<<" "<<i<<" cnt"<<cnt;
                break;
            }
        }
        if(cnt==6){
    
            if(i+1 <info.size() && (info[i][0]==info[i+1][0] || u.find(info[i+1][1])==u.end())) {
                flag = false;
                //cout<<"flag = 6"<<" "<<i;
                break;
            }
            else if(i+1 <info.size() && info[i][0]!=info[i+1][0] && info[i+1][1]=="WD"){
                cnt = 0;
            }
            else{
                cnt = 1;
                i++;
            }
        }
        i++;
    }
    if(flag==false) return "NO";
    else return "YES";
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int N ;
        cin>>N;
        vector<vector<string>>info(N,vector<string>(2));
        for(int i=0;i<N;i++){
            for(int j =0;j<2;j++){
                cin>>info[i][j];
            }
        }
        cout<<solve(N,info)<<endl;
        
    }
    
    return 0;
}