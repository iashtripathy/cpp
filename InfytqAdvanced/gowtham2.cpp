 
#include <bits/stdc++.h> 
using namespace std; 

int count(string str1, string str2) 
{ 
	int n = str1.size(), m = str2.size(); 

	if (m == 0) 
		return 1; 

    //created an empty array
	int dp[m][n]; 
	memset(dp, 0, sizeof(dp)); 

	for (int i = 0; i < m; i++) { 

		for (int j = i; j < n; j++) { 

			if (i == 0) { 
				if (j == 0){
                    if(str1[j] == str2[i]){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0; 
                    }
                } 
				
				else if (str1[j] == str2[i]) 
					dp[i][j] = dp[i][j - 1] + 1; 
				else
					dp[i][j] = dp[i][j - 1]; 
			} 

			else { 
				if (str1[j] == str2[i]) 
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]; 
				else
					dp[i][j] = dp[i][j - 1]; 
			} 
		} 
	} 

	return dp[m - 1][n - 1]; 
} 

// Driver code 
int main() 
{ 
	string str1,str2;
    cin>>str1;
    cin>>str2; 
	cout << count(str1, str2); 
	return 0; 
} 
