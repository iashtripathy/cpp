
//Code is wrong wont work

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int find_kth_child(int n,int k,vector<int>&arr){
    int step_size = 2,count = 0,i = 1;
    int temp = 0;
    while(true){
        ++count;
        cout<<arr[i]<<" "; 
        if(k==count){
            return arr[i];
        }
        
        if(i==n-1){
            i = 0;
            step_size += 2;
            goto here;
        }
        else if(i>n-1){
            step_size += 2;
        }
        i = (i+step_size) % n;
        here:        
        if(count==n){
            break;
        }
    }
    return -1;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        iota(begin(arr),end(arr),1);
        cout<<find_kth_child(n,k,arr)<<"\n";
    }
    return 0;
}
