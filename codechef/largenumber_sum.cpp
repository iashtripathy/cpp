#include<bits/stdc++.h>
using namespace std;


void calculate_large_sum(vector<int>&input1,vector<int>&input2,vector<int>&summ){
    int temp = 0,val;
    stack <int> s;
    int i,j;
    for(i = input1.size()-1 ,j = input2.size()-1 ; i>=0 && j>=0; i-- , j-- ){
        //cout<<"i = "<<i<<" "<<"j = "<<j<<endl;
        int inter;
        inter = input1[i] + input2[j];
        val = temp + inter; 
        if( floor(val / 10) == 1){
            temp = 1;
        }
        else{
            temp = 0;
        }
        summ.push_back(val%10);
    }
    while( i>=0 ){
        val = temp + input1[i]; 
        if( val / 10 == 1){
            temp = 1;
        }
        else{
            temp = 0;
        }
        summ.push_back(val%10);
        i--;
    } 
    while( j>=0 ){
        val = temp + input2[j]; 
        if( val / 10 == 1){
            temp = 1;
        }
        else{
            temp = 0;
        }
        summ.push_back(val%10);
        j--;
    }
    if(temp==1){
        summ.push_back(temp);
    }
    reverse(summ.begin(),summ.end());
}


//dividing the large value in summ vector by a
void divide_by(int a,vector<int>&res,vector<int>&q){
    int carry = 0,z;
    for(auto &x:res){
        z = carry + x;
        int temp = floor(z/a);
        q.push_back(temp);
        carry = (z-(temp*2))*10;
    }
}


//subtracting two large numbers
void subtract_large_numbers(vector<int>&input1,vector<int>&input2,vector<int>&diff){
    int br = 0,k,i,j;
    for(i = input1.size()-1 ,j = input2.size()-1 ; i>=0 && j>=0; i-- , j-- ){
        
        if(input1[i]<=input2[j]){
            if(input1[i]==input2[j] && br==0){
                goto here;
            }
            diff.push_back((10-br) + input1[i] - input2[j]);
            br = 1;
            continue;
        }

        here :
        diff.push_back(input1[i] - br - input2[j]);
        br = 0;
    }
    while(i>=0){
        if(br==1 && input1[i]==0){
            diff.push_back(9);
            br = 1;
            goto end;
        }
        diff.push_back(input1[i]-br);
        br = 0;
        end:
        i--;
    }
    reverse(diff.begin(),diff.end());
}

int main(){
    int T = 10;
    //cin>>T;
    while(T--){
        string a,b;
        int gt;
        vector<int> input1,input2,summ,diff,q1,q2;
        cin>>a>>b;
        if(a.length()>=b.length()){
            for(auto &x:a){
                input1.push_back(int(x)-48);
            }
            for(auto &x:b){
                input2.push_back(int(x)-48);
            }
            gt = 0;
        }
        else{
            for(auto &x:a){
                input2.push_back(int(x)-48);
            }
            for(auto &x:b){
                input1.push_back(int(x)-48);
            }
            gt = 1;
        }

        calculate_large_sum(input1,input2,summ);
/*         cout<<"Sum : ";
        for(auto &x:summ){
            cout<<x;
        }
        cout<<"\n";  */


        subtract_large_numbers(input1,input2,diff);
/*         cout<<"Diff : "; 
        if(gt==1){
            cout<<"-";
        }
        for(auto &x:diff){
            cout<<x;
        }
        cout<<"\n";  */

        divide_by(2,summ,q1);
        int check = 0;
        for(int i=0;i<q1.size();i++){
            if(q1[i]==0 && check==0 && i!=q1.size()-1){
                continue;
            }
            check = 1;
            cout<<q1[i];
        }
        cout<<"\n"; 


        divide_by(2,diff,q2);
        int check1 = 0;
        for(int i=0;i<q2.size();i++){
            if(q2[i]==0 && check1==0 && i!=q2.size()-1){
                continue;
            }
            check1 = 1;
            cout<<q2[i];
        } 
        cout<<"\n"; 
    }
    return 0;
}