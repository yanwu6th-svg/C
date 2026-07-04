#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> h;
queue<int> w;

bool test(int m){
    int Len=0;
    queue<int> q = w;
    for(int i=0;i<n;i++){
        if(m > h[i])Len=0;
        else Len++;
        if(!q.empty()&&Len == q.front()){
            q.pop();
            Len=0;
        }
    }
    return q.empty();
}


int main(){

    cin >> n >> k;

/*
                n=10;k=3;
*/

    h.assign(n,-1);
    for(int i=0;i<n;i++)cin >> h[i];
    for(int i=0;i<k;i++){
        int wi;
        cin >> wi;
        w.push(wi);
    }

/*
                h = {5 ,3, 7, 5 ,1, 7,5 ,3 ,8, 4};
                w.push(2);
                w.push(2);
                w.push(1);
*/

    int MAX = *max_element(h.begin(),h.end());

    int l=1,rr=MAX,m;
    int ans;
    while(l<=rr){
        m = l +(rr-l)/2;
        if(test(m)){
            ans = m;
            l = m+1;
        }else{
            rr = m-1;
        }
    }
    cout << ans;
}
