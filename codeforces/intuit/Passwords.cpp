#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int n,k;
    
    cin >> n >> k;
 
    vector< string > a(n);
 
    for(int i = 0;i < n;i++) cin >> a[i];
 
    string s;
    cin >> s;
 
    int c1 = 0, c2 = 0;
 
    for(int i = 0;i < n;i++) {
        if(a[i].size() < s.size()) c1++;
        else if(a[i].size() == s.size()) c2++;
    }
 
    cout << c1 + 1 + (c1 / k) * 5 << ' ' << c1 + c2 + ((c1 + c2 - 1) / k) * 5 << '\n';
    return 0;
}


