#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    int cnt = 0;
    int start = 1,i = 0;
    while(cnt<k){
        int inter = pow(2,i);
        while(cnt<k && inter--){
            cout<<start<<" ";
            ++cnt;
        }
        i++;
        start++;
    }
    return 0;
}
