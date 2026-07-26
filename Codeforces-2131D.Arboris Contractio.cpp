#include<bits/stdc++.h>
using namespace std;
int n,a,b;
vector<vector<int>> nums;
vector<bool> visited;
vector<int> par;
int l=0;
void dfs(int Len,int curr){
    if(nums[curr].empty()){
        if(l<max(Len,l)){
            l = max(Len,l);
            a = curr;
        }
        return;
    }
    for(int i:nums[curr]){
        if(visited[i] == false)continue;
        visited[i] = true;
        dfs(Len+1,i);
    }
    return;
}

int main(){
    cin >> n;
    nums.resize(n+1);
    visited.assign(n+1,false);
    int yy,gg;
    for(int i=0;i<n-1;i++){
        cin >> yy >> gg;
        nums[yy].push_back(gg);
        par[gg].push_back(yy);
    }
    int curr=1;
    visited[curr] = true;
    dfs(0,curr);
    
    
}
