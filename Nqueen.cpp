#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v1;
vector<int>v2;
bool cmp(const vector<int>&a,const vector<int>&b){
    int i = 0;
    while(i!=a.size()){
        if(a[i]<b[i]){
            return 1;
        }
        else if(a[i]>b[i]){
            return 0;
        }
        else{
            i++;    
        }
        
    }   
}
bool issafe(int *arr[],int n,int x,int y){
    if(x==n-1 && y==n-1){
        return 1;
    }
    else{
        for(int i=x+1,j=y+1;i<n,j<n;i++,j++){
            if(i<n && j<n && arr[i][j]==1){
                return 0;
            }
        }
        for(int j=y+1;j<n;j++){
            if(j<n && arr[x][j]==1){
                return 0;
            }
        }
        for(int i=x-1,j=y+1;i>=0,j<n;i--,j++){
            if(i>=0 && j<n && arr[i][j]==1){
                return 0;
            }
        }
    }
    return 1;
}
void printSolution(int *arr[],int n){
    //cout<<"[";
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(arr[i][j]==1){
                //cout<<j+1<<" ";
                v2.push_back(j+1);
            }
        }
                    //cout<<endl;
    }
    v1.push_back(v2);
    v2.clear();
    //cout<<"]";
}

bool nqueen(int *arr[],int n,int y){
    bool res = false;
    if(y<0){
        printSolution(arr,n);
        return 1;
    }
    for(int x=n-1;x>=0;x--){
        if(issafe(arr,n,x,y)){
                arr[x][y] = 1;
                //the below code in comments would be correct if the he asked is there a solution or not because if there is a solution then we return 1 and donnot check any further
                /*if(nqueen(arr,n,x,y-1)){
                    //print(matrix 

                    return 1;
                }*/
                // even if we have one solution our res should be true hence we do or operation
                res = nqueen(arr,n,y-1) || res;
                arr[x][y] = 0;
        }
    }
    return res;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    //int arr[11][11];
	    int *arr[n];
	    for(int i=0;i<n;i++){
	        arr[i] = (int *)calloc(n,sizeof(int));
	    }
	    //int arr[n][n] = {0};
	    //for(int x=n-1;x>=0;x--){
    	    if(!(nqueen(arr,n,n-1))){
    	        cout<<"-1";
    	    }
    	    else{
    	        sort(v1.begin(),v1.end(),cmp);
    	        
                for(int i=0;i<v1.size();i++){
                    cout<<"[";
                    for(auto x:v1[i]){
                        cout<<x<<" ";
                    }
                    cout<<"] ";
                }
                //cout<<"]";
    	    }
	    //}
        v1.clear();
	    cout<<endl;
	}
	return 0;
}