#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> t;
vector<int> e;
vector<int> s;


int main(){
    cin >> n >> m;
    t.assign(n,0);
    s.assign(m,0);
    e.assign(m,0);

    for(int i=0;i<n;i++)cin >> t[i];
    for(int i=0;i<m;i++)cin >> s[i] >> e[i];

    sort(s.begin(),s.end());
    sort(e.begin(),e.end());

    long long total=0;
    for(int i=0;i<n;i++){
        total += upper_bound(s.begin(),s.end(),t[i]) - s.begin() - (lower_bound(e.begin(),e.end(),t[i]) - e.begin());
    }


    cout << total;
}
