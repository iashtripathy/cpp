#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
    int T;
    cin>>T;
    while(T--){
        string expr;
        cin>>expr;
        stack<char>s;
        //cout<<expr;
        if(expr[0]==')' || expr[0]=='}' || expr[0]==']'){
            cout<<"not balanced";
            goto here;
        }
        //cout<<expr;
        s.push(expr[0]);
        for(int i = 1; i<expr.length(); i++){
            if(expr[i]=='{' || expr[i]=='[' || expr[i]=='('){
                s.push(expr[i]);
            }
            else{
                if(!s.empty()){
                    if(expr[i] == '}' and s.top() == '{'){
                        s.pop();    
                    }
                    else if(expr[i] == ']'  and s.top() == '['){
                        s.pop();
                    }
                    else if(expr[i] == ')' and s.top() == '('){
                        s.pop();
                    }
                    else{
                        cout<<"not balanced";
                        goto here;
                    }                    
                }
                else{
                    cout<<"not balanced";
                    goto here;
                }

            }
        }
        if(s.empty()==true){
            cout<<"balanced";
        }
        else{
            cout<<"not balanced";
        }
        here:
        cout<<endl;
        while(!s.empty()){
            s.pop();    
        }
        
    }
	return 0;
}