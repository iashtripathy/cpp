#include<bits/stdc++.h>
using namespace std;

int longest_substring_len(int s,int e,string str,int k){
	int left, right;
    vector<int>cnt(26,0);
	for (int i = s; i < e; i++) {
		cnt[str[i] - 'a'] ++;
	}

	for (int i = s; i < e; i++) {

		if (cnt[str[i] - 'a'] < k) {
			left = longest_substring_len(s,i,str,k);
			right = longest_substring_len(i + 1,e,str,k);

			return max(left, right);
		}
	}
	return e - s;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    string s;
    cin>>s;
    int k;
    cin>>k;
    int len = s.size();

    cout<<longest_substring_len(0,len,s,k)<<endl;
    return 0;
}






