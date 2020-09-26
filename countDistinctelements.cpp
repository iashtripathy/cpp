#include<bits/stdc++.h>
using namespace std;
int main(){
    //int arr[] = {10,20,20,10,30,40,10};
    //int arr[] = {10,10,10,10};
    int arr[] = {73}; 
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    int count = 0;
    unordered_map <int,int> m;
    for(int i=0;i<size;i++){
        ++count;
        if(m.find(arr[i])!=m.end()){
            m[arr[i]]++;    
        }
        else{
            m.insert({arr[i],m[arr[i]]++});
        }
        
        /* for(auto &x:m){
            cout<<x.first<<" "<<x.second<<" and ";
        } 
        cout<<endl; */
        if(count>=k){
            cout<<"size: "<<m.size()<<" ";
            if(m[arr[count-k]]==1){
                m.erase(arr[count-k]);
            }
            else{
                m[arr[count-k]]--;
            }
            
        }
    }
    return 0;
}