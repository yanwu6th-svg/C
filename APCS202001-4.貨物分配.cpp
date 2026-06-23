#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(vector<ll> &a,vector<int> &r,vector<int> &l,int curr){

    if(l[curr]!=-1&&l[curr]!=-1){
        a[curr] = dfs(a,r,l,l[curr]) + dfs(a,r,l,r[curr]);
        return a[curr];
    }
    else {
        return a[curr];
    }

}

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(2*n);
    vector<int> l(2*n,-1);
    vector<int> r(2*n,-1);
    vector<int> par(2*n,-1);
    vector<int> w(m);
    for(int i=n;i<2*n;i++){
        cin >> a[i];
    }

    for(int i=0;i<m;i++){
        cin >> w[i];
    }

    int e,q,t;
    for(int i=1;i<n;i++){
        cin >> e >> q >> t;
        l[e] = q;
        r[e] = t;
        par[q] = e;
        par[t] = e;
    }

    ll v = dfs(a,r,l,1);

    for(int i=0;i<m;i++){

        int o=1;
        while(l[o] != -1||r[o] != -1){
                if(a[l[o]] <= a[r[o]]){
                    o = l[o];
                }else{
                    o = r[o];
                }
        }

        int tmp=o;
        while(tmp != -1){
            a[tmp] += w[i];
            tmp = par[tmp];
        }
        cout << o <<" ";
    }

    }

