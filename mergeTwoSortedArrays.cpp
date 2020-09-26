/*
O(m+n)log m solution where n is size of arr1 and m is size of arr2
*/
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    
	    //min heap
	    make_heap(arr1,arr1+n,greater<int>());
	    make_heap(arr2,arr2+m,greater<int>());
	    int i = 0;
	    int j = 0;
	    
	    while(i<n && j<m){
	        if(arr2[j]<arr1[i]){
	            int temp = arr1[i];
	            arr1[i] = arr2[j];
	            arr2[j] = temp;
	            pop_heap(arr2,arr2+m,greater<int>());

	            push_heap(arr2,arr2+m,greater<int>());

	        }
	        i++;
	    }
	    sort(arr2,arr2+m);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} 