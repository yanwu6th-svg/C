#include<bits/stdc++.h>
using  namespace std;

int main(){
int l,n;
cin >> n >> l;
vector<pair<int ,int>> nums(n);

int e,r;
for(int i =0;i<n;i++){
   cin >> r >> e;
   nums[i] = {e,r};
}

sort(nums.begin(),nums.end());

vector<int> a={0,l};

    long long res=0;
for(int i=0;i<n;i++){
    int it = lower_bound(a.begin(),a.end(),nums[i].second)- a.begin();
    res += a[it] - a[it-1];
    a.insert(a.begin() + it,nums[i].second);

}
cout << res;

}
