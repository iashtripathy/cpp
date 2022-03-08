#include<bits/stdc++.h>
using namespace std;
int minPalindrome(int left,int right,string s){
    if (left > right) return INT_MAX;
    //eg : "A"
    if (left == right) return 0;
    //eg: "AB"
    if (left == right - 1) {
        if(s[left]==s[right]) return 0;
        else return 1;
    }   

    if(s[left]==s[right]) return minPalindrome(left+1,right-1,s);
    else return 1 + min(minPalindrome(left+1,right,s),minPalindrome(left,right-1,s));
    
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    string s;
    cin>>s;
    int len = s.size();

    cout<<minPalindrome(0,len-1,s);
    return 0;
}


