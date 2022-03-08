#include<bits/stdc++.h>
using namespace std;
int main(){
    int p1,p2,p3,q,e,r;
    cin>>p1>>p2>>p3>>q>>e>>r;
    int a1 = p1-q;
    int a2 = p2-q;
    int a3 = p3-q;
    int a = ((e-r) - (a1+a2+a3+q) )/3;
    int firstQuestion = a + a1 + a3 + q;
    int oneQuestion = 3*a;
    cout<<firstQuestion<<endl;
    cout<<oneQuestion;
    return 0;
}