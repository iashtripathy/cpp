#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    //endif

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_map<char,int>um;
        um['r'] = 0;
        um['b'] = 0;
        um['g'] = 0;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='r') um['r'] = 1;
            else if(s[i]=='g') um['g'] = 1;
            else if(s[i]=='b') um['b'] = 1;
            else if(s[i]=='R'){
                if(um['r']==1) ++cnt;
            }
            else if(s[i]=='G'){
                if(um['g']==1) ++cnt;
            }
            else if(s[i]=='B'){
                if(um['b']==1) ++cnt;
            }
        }
        if(cnt==3) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
        
    }

    return 0;
}


