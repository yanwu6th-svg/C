#include<bits/stdc++.h>
using namespace std;

int main(){
int n=0,k=0;
cin >> n >> k;

vector<int> nums(n);
for(int i=0;i<n;i++){
    cin >> nums [i];
}

sort(nums.begin(),nums.end(),[](int a,int b){
     return a<b;
     });
int D = int((*nums[n-1]-*nums[0]) / 2);
int h=0;
int r=k;
while(true){
    if(){}
    r--;
    int u = nums[h] + D;
    while(nums[h] > u){
        h++;
    }
    
}
}
