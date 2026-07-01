#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;
vector<ll> nums;
vector<ll> nums_pre;

int F(int l,int r,int a,int b){
    double sum=0;
    if(l==1){
        sum = nums_pre[r];
    }else{
        sum = nums_pre[r] -  nums_pre[l-1];
    }

    sum = sum*a/(double)(a+b);
    if(l!=1)sum += nums_pre[l-1];
    int k=lower_bound(nums_pre.begin()+1,nums_pre.end(),sum) - nums_pre.begin();

    return k;
}

int main(){
    cin >> n >> m;
    nums.assign(n+1,0);
    nums_pre.assign(n+1,0);
    ll y=0;
    for(int i=1;i<n+1;i++){
        cin >> nums[i];
        y += nums[i];
        nums_pre[i] = y;
    }

    int l,r,a,b;
    int ans[m];
    for(int e=0;e<m;e++){
        cin >> l >> r >> a >> b;
        ans[e] = F(l,r,a,b);
    }

    for(int i=0;i<m;i++){
        cout << ans[i];
        if(i != m-1){
            cout << '\n';
        }
    }
}
