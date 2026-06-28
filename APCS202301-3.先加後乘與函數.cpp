#include<bits/stdc++.h>
using  namespace std;
using ll = long long;
string str;
int now=0;
ll factor();
ll sol();
ll f(){
    now+=2;

    vector<ll> a;
    while(now < str.size()&&str[now] != ')'){
        if(now < str.size()&&str[now] == ','){
            now++;
        }
        ll v = sol();
        a.push_back(v);
    }
    now++;

    ll Max = *max_element(a.begin(),a.end());
    ll Min = *min_element(a.begin(),a.end());
    return Max - Min;
}

ll factor(){
    ll e=0;
    if(now < str.size()&&str[now] == 'f'){
        e = f();
    }else{
        while(now < str.size()&&isdigit(str[now])){
            e *= 10;
            e += str[now] -'0';
            now++;
        }
    }
    return e;
}

ll sol(){
    ll num = factor();

    vector<ll> mul;
    while(now < str.size()&&str[now] != ')'&&str[now] != ','){
        if(str[now] == '+'){
            now++;
            num += factor();
        }
        if(str[now] == '*'){
            mul.push_back(num);
            now++;
            num = factor();
        }
    }

    for(ll i : mul){
        num *= i;
    }

    return num;
}

int main(){
    cin >> str;

    cout << sol();
}
