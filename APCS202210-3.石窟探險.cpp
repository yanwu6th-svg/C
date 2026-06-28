#include<bits/stdc++.h>
using  namespace std;
vector<int> nums;
long long ans=0;

void dfs(int &now,int par){
    if(nums[now] == 0){
        return ;
    }

    if(par != -1){
        ans += abs(nums[par] - nums[now]);
    }

    int r=now;
    if(nums[now]%2 == 1){
        now++;
        dfs(now,r);
        now++;
        dfs(now,r);
        now++;
        dfs(now,r);
    }else{
        now++;
        dfs(now,r);
        now++;
        dfs(now,r);
    }
    return;
}

int main(){
    string a;
    getline(cin,a);
    stringstream ss;
    ss << a;
    while(ss >> a){
        nums.push_back(stoi(a));
    }
    int now=0;
    dfs(now,-1);
    cout << ans;
}
