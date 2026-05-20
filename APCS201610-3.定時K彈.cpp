#include<bits/stdc++.h>
using namespace std;

int main(){
int n=0,m=0,k=0;
cin >> n >> m >> k;

int r=0;
for(int i = n-k+1;i<=n;i++){
    r = (r+m)%i;
}
cout << r+1;
}
