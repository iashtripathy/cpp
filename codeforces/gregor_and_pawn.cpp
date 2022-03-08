#include<bits/stdc++.h>
using namespace std;
int solve(int n,string s1,string s2){
    int i = n-1;
    int count = 0;
    vector <bool> a(n,false);
    while(i>=0){
        if(i+1<n && i-1>=0){
            if(s2[i]-'0'==1){
                
                if(!a[i] && s1[i]-'0'==0){
                    a[i] =true;
                    ++count;  
                }
                else if(!a[i+1] && s1[i+1]-'0'==1){
                    a[i+1] = true;
                    ++count;
                }
                else if(!a[i-1] && s1[i-1]-'0'==1){
                    a[i-1] = true;
                    ++count;
                }

                
            }
        } 
        else if(i+1>=n && i-1>=0){
            if(s2[i]-'0'==1){
                
                if(!a[i] && s1[i]-'0'==0){
                    a[i] =true;
                    ++count;  
                }
                else if(!a[i-1] && s1[i-1]-'0'==1){
                    a[i-1] = true;
                    ++count;
                }
                
            }
        }
        else if(i-1<0 && i+1<n){
            if(s2[i]-'0'==1){
                
                if(!a[i] && s1[i]-'0'==0){
                    a[i] =true;
                    ++count;  
                }
                else if(!a[i+1] && s1[i+1]-'0'==1){
                    a[i+1] = true;
                    ++count;
                }
                
            }
        }
        i--;
    }
    return count;
}
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
        int n;
        cin>>n;
        string enemy,gregor;
        cin>>enemy;
        cin>>gregor;
        cout<<solve(n,enemy,gregor)<<"\n";
    }

    return 0;
}