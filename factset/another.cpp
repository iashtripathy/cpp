#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int minOperations(vector <int> arr1, vector<int> arr2, int i, int j,
				int n, map<pair<int, int>, int> table)
{
	

	pair<int, int> key = {i, j};
	
	if (arr1 == arr2)
		return 0;
	if (i >= n || j >= n)
		return 0;

	if (table.find(key) != table.end())
		return table[key];

	if (arr1[i] < arr2[j])
		return 1 + minOperations(
			arr1, arr2, i + 1, j + 1, n, table);


	table[key] = max(
		minOperations(arr1, arr2, i, j + 1, n, table),
		minOperations(arr1, arr2, i + 1, j, n, table));


	return table[key];
}

int getMinimumMoves(vector<int>arr)
{
    int n = arr.size();
	vector<int> brr;

	for(int i = 0; i < n; i++)
		brr.push_back(arr[i]);

	sort(brr.begin(), brr.end());

	if (brr == arr)
		return 0;

	else
	{
		map<pair<int, int>, int> table;
		
		return n - minOperations(brr, arr, 0, 0, n, table);
	}
}

int main(){

    vector <int> arr = {5,1,3,2};
    int result = getMinimumMoves(arr); 
    cout<< result;
    return 0;
}
