#include<bits/stdc++.h>
using namespace std;

vector<string> a;
int k=1;

long long h(),g(),f();

long long h(){
    long long x=0,y=0,z=0;

    if(a[k] == "h"){

        k++;x = h();
    }else if(a[k] == "g"){
        k++;x = g();
    }else if(a[k] == "f"){
        k++;x = f();
    }else{
        x = stoll(a[k]);k++;
    }


   if(a[k] == "h"){
        k++;y = h();
    }else if(a[k] == "g"){
        k++;y = g();
    }else if(a[k] == "f"){
        k++;y = f();
    }else{
        y = stoll(a[k]);k++;
    }

    if(a[k] == "h"){
        k++;z = h();
    }else if(a[k] == "g"){
        k++;z = g();
    }else if(a[k] == "f"){
       k++; z = f();
    }else{
        z = stoll(a[k]);k++;
    }

    return 3*x -2*y +z;
}

long long g(){
    long long x=0,y=0;

    if(a[k] == "h"){

        k++;x = h();
    }else if(a[k] == "g"){
        k++;x = g();
    }else if(a[k] == "f"){
        k++;x = f();
    }else{
        x = stoll(a[k]);k++;
    }


   if(a[k] == "h"){
        k++;y = h();
    }else if(a[k] == "g"){
        k++;y = g();
    }else if(a[k] == "f"){
        k++;y = f();
    }else{
        y = stoll(a[k]);k++;
    }
    return 2*x + y -7;
}

long long f(){
    long long x=0;


    if(a[k] == "h"){

        k++;x = h();
    }else if(a[k] == "g"){
        k++;x = g();
    }else if(a[k] == "f"){
        k++;x = f();
    }else{
        x = stoll(a[k]);k++;
    }

    return 2*x -3;
}

int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    string t;
    while(ss >> t){
        a.push_back(t);
    }

    string e = a[0];

    long long res=0;
    if(e == "h"){
        res = h();
    }else if(e == "g"){
        res = g();
    }else{
        res = f();
    }

    cout << res;
}
