#include<bits/stdc++.h>
using namespace std;

bool j(int D,vector<int> nums,int k){
    if(D ==1)return true;
    int a=k;
    int h=0;
    bool f=false;
	int n = nums.size();
    while(a>=0){
        int H = nums[h] + D;
        a--;
        while(nums[h] <= H){
            h++;
            if(h == n-1){
                f =true;
                break;
            }
        }
        if(f == true)return true;
    }
    if(f == false)return false;
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
    
int r =0;
int l=nums[n-1]-nums[0];
int mid = l + (l-r)/2;

int res = INT_MAX;
while(r<=l){
    mid = l + (l-r)/2;
    if(j(mid,nums,k)){
        res = mid;
        l = mid-1;
    }else{
        r = mid +1;
    }
}
cout << res;

}