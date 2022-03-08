#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countPalindromes(char *s1,int cnt){
    string s;
    string alt;
    int tcount = 0;
    for(int i=0;i<cnt;i++){
        if(int(s1[i]) != 32) {
           s = s + s1[i];
        }
        else{
            alt = s;
            reverse(alt.begin(),alt.end());
            if(alt.compare(s)==0){
                ++tcount;
            }
            s.clear();
        }
    
    }
    //for the last string since after the last string there might not be any space
    if(alt.length()>0){
        alt = s;
        reverse(alt.begin(),alt.end());
        if(alt.compare(s)==0){
            ++tcount;
        }
    }


    return tcount;

}

int main(){


    char s1[] = "Length of the String madam liril";
    
    cout<<countPalindromes(s1,strlen(s1));
    return 0;
}