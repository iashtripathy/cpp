#include<bits/stdc++.h>
using namespace std;
    bool cmp( pair<string,int>&p1,pair<string,int>&p2){
        return p1.second<p2.second;
    }
int main(){
    string str;
    getline(cin,str);
    int n;
    cin>>n;
    vector<pair<string,string>>v;
    while(n--){
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        v.push_back({s1,s2});
    }
    unordered_map <string,int> final;
    vector <pair<string,int>> temp;
    int j = 0;

    for(int i=0;i<v.size();i++){
        if( str==v[i].first || str==v[i].second){
            final.insert({v[i].first,j++});
            final.insert({v[i].second,j++});
        }
    }
    for(auto &x:final){
        temp.push_back(x);
    }
    //sort(temp.begin(),temp.end(),cmp);

    for(auto &x:temp){
        cout<<x.first<<" ";
    }

    return 0;
}