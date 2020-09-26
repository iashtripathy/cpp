#include <iostream>
#include<bits/stdc++.h>
# define n 9
using namespace std;

bool isSafe(int *matrix[],int x,int y,int value){
    //for row
    for(int j=0;j<n;j++){
        if(matrix[x][j]==value){
            return false;
        }
    }
    //for column
    for(int i=0;i<n;i++){
        if(matrix[i][y]==value){
            return false;
        }
    }
    //for subgrid
    int subGridSize = sqrt(n);
    int startX = x - (x%subGridSize);
    int startY = y - (y%subGridSize);
    for(int i = startX;i<subGridSize+startX;i++){
        for(int j = startY;j<subGridSize+startY;j++){
            if(matrix[i][j]==value){
                return false;
            }
        }
    }
    return true;
}
bool solve(int *matrix[]){
    int i,j;

    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(matrix[x][y]==0){
                i = x;
                j = y;
                goto here;
                //break;
            }
            else{
                if(x==n-1 && y==n-1){
                    return true;
                }
            }
        }
    }
    /*if(i==9){
        return true;
    }*/
    here:
    //cout<<"\ni= "<<i<<" j= "<<j<<endl;
    for(int value=1;value<=n;value++){
        if(isSafe(matrix,i,j,value)){
            matrix[i][j] = value;
            /*if(i==n-1 && j==n-1){
                return true;
            }*/
            if(solve(matrix)){
                return true;    
            }
            matrix[i][j] = 0;
        }    
    }
    return false;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int *matrix[n];
	    for(int i=0;i<n;i++){
	        matrix[i] = (int *)calloc(n,sizeof(int));
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>matrix[i][j];
	        }
	    }
	    if(solve(matrix)){
	        for(int i =0;i<n;i++){
	            for(int j=0;j<n;j++){
	                cout<<matrix[i][j]<<" ";
	            }
	            //cout<<endl;
	        }
	    }
	    cout<<endl;
	    for (int i = 0; i < n; i++){
            int *currentIntPtr = matrix[i];
            free(currentIntPtr);
        }
	}
	return 0;
}