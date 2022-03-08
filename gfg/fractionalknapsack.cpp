// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static cmp(Item x,Item y){
        return ((x.value/x.weight) > (y.value/y.weight));
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        int rem_weight = W,i=0;
        double tot_value=0;
        for(int i=0;i<n;i++){
            cout<<"value : "<<arr[i].value<<" ";
            cout<<"weight : "<<arr[i].weight<<"\n";
        }
        while(i!=n && rem_weight-arr[i].weight>0){
            tot_value += arr[i].value;
            rem_weight = rem_weight-arr[i].weight;
            i++;
            
            
        }
        //cout<<"tot weight="<<tot_value<<"\n";
        //cout<<arr[i].weight<<" "<<rem_weight<<"\n";
        if(i!=n){
            tot_value += (rem_weight) * (arr[i].value/arr[i].weight);    
        }
        
        return tot_value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends