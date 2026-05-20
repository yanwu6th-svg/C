#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
void dfs(int curr_node,int curr_dist,int parent,int& farest_node,int& farest_dist){
    if(curr_dist >=farest_dist){
        farest_dist = curr_dist;
        farest_node = curr_node;
    }

    for(int i : adj[curr_node] ){
         if(i == parent) continue;
        dfs(i,curr_dist+1,curr_node,farest_node,farest_dist);
    }
}
int main(){

int n=0;
cin  >> n;

adj.resize(n);
int a=0,b=0;

for(int i=0;i<n-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
}

int farest_node=-1;
int farest_dist  = -1;
dfs(0,0,-1,farest_node,farest_dist);

int m = farest_node;
farest_node = -1;
farest_dist  = -1;
dfs(m,0,-1,farest_node,farest_dist);

cout << farest_dist;

}
