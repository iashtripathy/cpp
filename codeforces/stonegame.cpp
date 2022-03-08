#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int min_value = arr[0],max_value = arr[0];
        int min_index = 0,max_index = 0;
        for(int i=1;i<n;i++){
            if(arr[i]<min_value){
                min_index = i;
                min_value = arr[i];
            }
            else if(arr[i]>max_value){
                max_index = i;
                max_value = arr[i];
            }
        }
        int from_left,from_right,from_middle;
        if(min_index<=max_index){
            from_left = min_index + (max_index-min_index) + 1;
            from_right = n - min_index;
            from_middle = (n-max_index) + min_index + 1;
        }
        else{
            from_left = max_index + (min_index-max_index) + 1;
            from_right = n - max_index;
            from_middle = (n-min_index) + max_index + 1;
        }
        int res = min(from_left,from_right);
        res = min(res,from_middle);
        cout<<res<<"\n";
    
    }
    return 0;
}