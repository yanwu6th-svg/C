#include<bits/stdc++.h>
using namespace std;


int main(){
int n=5;
cin >> n;
vector<vector<int>> nums(n,vector<int> (2));

for(vector<int> &a : nums){
    for(int &i : a){
        cin >> i;
    }
}
int h=0,g=0;

sort(nums.begin(),nums.end(),[](vector<int> a,vector<int> b){
     return a[0] < b[0];
});

int res=0;
int L=nums[0][0];
int R=nums[0][1];

for(int i=1;i<nums.size();i++){
    if(nums[i][0] <= R){
        R = max(nums[i][1],R);
    }else{
        res += R-L;
        L=nums[i][0];
        R=nums[i][1];
    }
}
res += R-L;

cout << res;

}
