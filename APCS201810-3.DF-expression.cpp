#include<bits/stdc++.h>
using namespace std;
string str;
int k;
int FIND(int n){
    int res=0;

    if(str[k] == '1'){
        k++;
        return n*n;
    }else if(str[k] == '2'){
        int g = n/2;
        k++;
        res += FIND(g);
        res += FIND(g);
        res += FIND(g);
        res += FIND(g);
    }else if(str[k] == '0') k++;

    return res;
}

int main(){
cin >> str;
int n=0;
cin >> n;

k=0;

cout << FIND(n);
}
