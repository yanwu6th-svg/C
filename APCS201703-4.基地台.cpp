#include<bits/stdc++.h>
using namespace std;

bool j(int D,vector<int> nums,int k){
    int count  =1;
    int H=nums[0]+D;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > H){
            count ++;
            H=nums[i]+D;
        }
    }
    return count <= k;
}


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
    
int l =0;
int r=nums[n-1]-nums[0];
int mid = l + (l-r)/2;

int res = INT_MAX;
while(r>=l){
    mid = l + (r-l)/2;
    if(j(mid,nums,k)){
        res = mid;
        r = mid-1;
    }else{
        l = mid +1;
    }
}
cout << res;

}