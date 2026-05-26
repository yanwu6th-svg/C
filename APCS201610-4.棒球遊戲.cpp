#include<bits/stdc++.h>
using namespace std;

void run(string h,int& res,vector<int>& place){
   if(h == "1B"){
    res += place[2];
    place[2] =place[1];
    place[1]=place[0];
    place[0] =1;
   }else if(h == "2B"){
    res += place[2]+place[1];
    place[2] =place[0];
    place[1] =1;
    place[0] =0;
   }else if(h == "3B"){
    res += place[2]+place[1]+place[0];
    place[2]=1;
    place[1]=0;
    place[0]=0;
   }else{
    res += place[2]+place[1]+place[0]+1;
    place[2]=0;
    place[1]=0;
    place[0]=0;
   }
};


int main(){
vector<vector<string>> nums(9);

int n=0;
for(int i=0;i<9;i++){
    cin >> n;
    nums[i].resize(n);
    for(int j=0;j<n;j++){
        cin >> nums[i][j];
    }
}
int times=0;
cin >> times;

int u=0,v=0;
int res=0;
vector<int> place(3,0);
int out=0;
while(true){
    if(times == 0){
        break;
    }

    string h = nums[u][v];
    if(h == "1B"||h == "2B"||h == "3B"||h == "HR"){
        run(h,res,place);
    }else{
        out++;
        times--;
        if(out == 3){
            place[0] = place[1] = place[2] =0;
            out=0;
        }
    }
    u++;
   if(u == 9){
        u=0;
        v++;
    }
}
cout << res;
}
