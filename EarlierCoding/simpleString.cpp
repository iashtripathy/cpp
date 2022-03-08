#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>k;
    
        string str;
        cin>>str;
        //getline(cin,str);

        stack <char> s;
        char ch;
        
        for(int i=0;i<str.length();i++){
        
            s.push(str[i]);
            while(k!=0 && s.size()>1){
                ch = s.top();
                s.pop();
                if(ch!=s.top()){
                    s.pop();
                    s.push('*');
                    k--;
                }
                else{
                    s.push(ch);
                    break;
                }
            }
        }
        cout<<s.size()<<"\n";
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    return 0;
}