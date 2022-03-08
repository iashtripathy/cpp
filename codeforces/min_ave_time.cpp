#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    /*
    for(auto &x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }*/

    //sort the vector of pairs on the basis of arrival times
    sort(v.begin(), v.end());
    ll summ = 0;
    
    //use to keep track of all the shortest jobs arrived till this time
    set <pair<int,int>> s;
    ll time_till_now = v[0].first;
    int it = 0;

    while (it < n || s.size()) {

        //This loop is to add all the customers who would have arrived by time_till_now
        while (it < n && v[it].first <= time_till_now) {
            s.insert({v[it].second, it});
            ++it;
        }
        if (s.empty()) {
            time_till_now = v[it].first;
        } else {
            int i = (*s.begin()).second;
            s.erase(s.begin());
            time_till_now += v[i].second;
            summ += time_till_now-v[i].first;
        }
    }
    cout << summ / n << endl;
    return 0;
}