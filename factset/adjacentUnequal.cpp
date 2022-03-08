
#include <bits/stdc++.h>
using namespace std;


vector<int> minimalOperations(vector <string> s)
{

    vector<int> arr;
    for(auto &x : s){

	    int n = x.length();

	    int ans = 0;

	    int i = 0;

	    while (i < n) {

	    	int j = i;

	    	while (x[j] == x[i] && j < n) {
	    		j++;
	    	}

	    	int diff = j - i;

	    	ans += diff / 2;
	    	i = j;
	    }    
        arr.push_back(ans);
    
    }


    return arr;
}

int main()
{
	vector <string> str = {"add" ,"boook","break"};
	vector <int> arr = minimalOperations(str);
    for(auto &array : arr){
        cout<< array <<endl;
    }
	return 0;
}
