#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<int> d;
int n,k;
vector<int> par;

int Find_set(int i){
    if(i == par[i])return i;
    return par[i] = Find_set(par[i]);
}

void unite(int i,int j){
    int a = Find_set(i);
    int b = Find_set(j);
    if(a != b)par[a] = b;
}

bool test(int m){
    par.assign(n,-1);
    for(int i=0;i<n;i++){
            par[i] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(grid[i][j] < m){
                unite(i,j);
            }
        }
    }
    set<int> s;
    for(int i : par){
        s.insert(Find_set(i));
    }


    if(s.size() >= k)return true;
    return false;

}


int main(){

        cin >> n >> k;
/*
                    n=5;k=3;
*/
        grid.assign(n,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int hhh;
                cin >> hhh;
                if(i!=j && i<j){
                    d.push_back(hhh);
                }
                grid[i][j] = hhh;
            }
        }

 /*
                    grid = {{0,5,6,1,3},{5,0,3,4,2},{6,3,0,4,7},{1,4,4,0,5},{3,2,7,5,0}};
                    d = {1,2,3,3,4,4,5,5,6,7};
*/
        sort(d.begin(),d.end());

        int l=0;int r=d.size()-1;int m;
        int ans;

        while(r>=l){
             m = l + (r-l)/2;
             int f = d[m];

            if(test(f)){
               ans = f;
               l = m+1;
            }else{
               r = m-1;
            }
        }



        cout << ans;
}
