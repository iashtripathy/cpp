#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifndef ONLINE JUDGE
    freopen("gvp_placements.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //endif

    int t = 62;
    vector<pair<int,int>>v;
    while(t--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end(),cmp);
    int stu_cnt = 0,sal_count=0;
    int stu_cnt_gt5l = 0;

/*     for(auto &x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }

    cout<<endl<<endl<<endl<<"------------------------------"<<endl<<endl; */

    vector<pair<int,int>>res;
    res.push_back({v[0].first,v[0].second});
    
    for(int i=1;i<v.size();i++){
        int k = i;
        int cum_num = 0;
        if(v[i].second!=v[i-1].second){
            res.push_back({v[i].first,v[i].second});
        }
        else{
            while(v[i].second==v[i-1].second){
                cum_num+=v[i].first;
                ++i;
                //v.erase(v.begin()+i);
            }
            --i;
            res[res.size()-1].first+=cum_num;
        }

        
    }
    for(auto &x:res){
        if(x.second>=600000){
            stu_cnt_gt5l+=x.first;
        }
        stu_cnt+=x.first;
        sal_count+=(x.second*x.first);
        cout<<x.first<<" "<<x.second<<" "<<stu_cnt<<endl;
    }
    int median;

    cout<<endl<<endl;
    //cout<<"Median Salary is : "<<median<<endl<<endl;
    cout<<"Average Salary is : "<<sal_count/stu_cnt<<endl<<endl;
    cout<<"No of students with salary > 5LPA is : "<<stu_cnt_gt5l<<endl<<endl;
    return 0;
}


