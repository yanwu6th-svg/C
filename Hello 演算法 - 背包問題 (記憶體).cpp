#include<bits/stdc++.h>
using namespace std;

int knapsackDFS(int c,int p ,int &n,vector<vector<int>> &mem,vector<int> &vals,vector<int> &wegs){
if(c == 0 || p == n){
    return 0;
}

if(mem[c][p] != -1){
  return   mem[c][p];
}
int y=-1;
if(c-wegs[p] >=0){
    y= knapsackDFS(c-wegs[p],p+1,n,mem,vals,wegs)+vals[p];
}

int h = knapsackDFS(c,p+1,n,mem,vals,wegs);

mem[c][p] = max(y,h);
return mem[c][p];
}

int main(){
vector<int> vals = {60,110,120};
vector<int> wegs = {10,20,30};
int c=30,n =vals.size();
vector<vector<int>> mem(c+1,vector<int> (n,-1));

int p=0;


 cout << knapsackDFS(c,p,n,mem,vals,wegs);;
}
