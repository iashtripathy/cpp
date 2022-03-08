#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n;
        cin>>q;
        string s;
        cin>>s;
        
        while(q--){
            int l,r;
            cin>>l>>r;
            int diff = r-l+1;
            l = l-1;
            r = r-1;
            bool flag = false;
            int k = -1,end = n;
            int first = 1;
            int cnt = 0;
            while(l<=r){

                for(int i=k+1;i<=end-1;i++){
                    if(s[l]==s[i]){
                        k = i;
                        ++cnt;
                        ++l;
                        break;
                    }
                }
                if(cnt==diff && first!=1) break;
                for(int j=end-1;j>=k+1 && (cnt>=diff ? l!=r : 1);j--){
                    if(s[r]==s[j]){
                        end = j;
                        --r;
                        ++cnt;
                        break;
                    }
                }
                if(first==1 && end-k+1<=diff) {
                    flag = true;
                    
                }
                first = 2;
                if(flag){
                    cout<<"NO"<<endl;
                    break;
                }
                if(cnt==diff && first!=1) break;
                
            }
            cout<<cnt<<" "<<diff<<" "<<flag<<endl;
            if(!flag && cnt==diff){
                cout<<"YES"<<endl;
            }

        }
    }

    return 0;
}



/*
BEST SOLUTION

    while(q--){
        int l,r; cin>>l>>r;
        --l, --r;
        bool flag = false;
        for(int i = 0;i<l;i++){
            if(s[i] == s[l]){
                flag = true;
                break;
            }
        }
        for(int i = r+1;i<n;i++){
            if(s[i] == s[r]){
                flag = true;
                break;
            }
        }
        cout<<(flag?"YES\n":"NO\n");
    }

*/