#include <bits/stdc++.h>
using namespace std;

int check(string s1,string s2){
    int s1_len = s1.size();
    int s2_len = s2.size();
    
    if(abs(s1_len-s2_len)>1){
        return 0;
    }
    else if(s1_len>s2_len){
        int i=0,j=0;
        while(i!=s1_len){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1_len && j!=s2_len){
            return 0;
        }
        else if(j==s2_len){
            return 1;
        }
    }
    else if(s2_len>s1_len){
        int i=0,j=0;
        while(j!=s1_len){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i!=s1_len && j==s2_len){
            return 0;
        }
        else if(i==s2_len){
            return 1;
        }        
    }
    else if(s1_len==s2_len){
        int count = 0,i = 0,j=0;
        while(i!=s1_len || j!=s2_len){
            if(s1[i]!=s2[j]){
                ++count;
            }
            i++;
            j++;            
        }
        if(count==1){
            return 1;
        }
        else{
            return 0;
        }

    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s1,s2;
        
        getline(cin,s1);
        //cin.ignore();
        getline(cin,s2);
        //cin.ignore();
        cout<<s1<<" "<<s2<<"\n";
        if(check(s1,s2)==1){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }        
    }

    

    return 0;
}
