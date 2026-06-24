#include<bits/stdc++.h>
using  namespace std;

int main(){
 int n=0;
 cin >> n;
vector<pair<int,int>> nums(n);
int a,b;
for(int i=0;i<n;i++){
    cin >> a >> b;
    nums[i] = {a,b};
}

sort (nums.begin(),nums.end(),[](auto a ,auto b){
      if(a .first!= b.first){
        return a.first < b.first;
      }else{
        return a.second < b.second;
      }
});

int k=0;
vector<int> v;
v.push_back(nums[0].second);
for(int i=1;i<n;i++){
    int d = nums[i].second;

    if(v.empty() || v.back() <= d){
        v.push_back(d);
    }else{
        v[upper_bound(v.begin(),v.end(),d) - v.begin()] = d;
    }
}
cout << v.size();

}
