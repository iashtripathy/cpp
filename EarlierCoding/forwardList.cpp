#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
int main(){
    forward_list <int> l = {10,15,20};
    l.assign({100,200});
    for(auto x:l){
        cout<<x<<" ";
    }
    return 0;
}