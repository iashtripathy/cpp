
#include<bits/stdc++.h>
using namespace std;


int main()
{
	string str1,temp1,temp2;
    cin>>str1;
    temp1 = str1;
    temp2 = str1;

	reverse(temp1.begin()+1, temp1.end());
	reverse(temp1.begin(), temp1.end());

    reverse(temp2.begin(),temp2.end()-1);
	reverse(temp1.begin(), temp1.end());

	if(temp1==temp2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
	return 0;
}
