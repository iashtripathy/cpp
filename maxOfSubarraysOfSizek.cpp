#include<bits/stdc++.h>
using namespace std;
int main(){
    //int arr[] = {10,8,5,12,15,7,6};
    int arr[] = {10,20,1,1,2,-3,5,5,30};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    deque <int> dq;

    for(int i=0;i<arrLen;i++){
        //count++;
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);

        if(dq.back()>=k-1){
            cout<<arr[dq.front()]<<endl;
            if(dq.back()-dq.front()==k-1){
                dq.pop_front();
            }          
        }
 

    }
    return 0 ;
}