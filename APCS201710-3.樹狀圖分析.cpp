#include<bits/stdc++.h>
using namespace std;

long long total=0;
long long Find_H(int curr,vector<vector<int>> &nums){
    if(nums[curr].empty()){
        return 0;
    }
    long long mx=0;
    for(int i : nums[curr]){
        mx = max(mx,Find_H(i,nums)+1);
    }

    total += mx;
    return mx;
}


int main(){
    int n=7;
    cin >> n;
    vector<vector<int>> nums(n);

    for(int i=0;i<n;i++){
        int a=0;
        cin >> a;
        for(int j=0;j<a;j++){
            int h=0;
            cin >> h;
            h--;
            nums[i].push_back(h);
        }
    }
    int u=0;
    while(nums[u].empty()){
        u++;
    }

    int root=0;
    vector<int> e(n,0);
    for(int i=0;i<n;i++){
        for(int j : nums[i]){
            e[j] = 1;
        }
    }

    for(int i=0;i<n;i++){
        if(e[i] == 0){
            root = i;
            break;
        }
    }
    cout << root +1 <<'\n';

    long long H=Find_H(root,nums);
    cout << total;
}
