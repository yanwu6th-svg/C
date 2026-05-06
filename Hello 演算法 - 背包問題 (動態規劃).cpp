#include<bits/stdc++.h>
using namespace std;


int main(){
vector<int> vals = {60,110,120};
vector<int> wegs = {10,20,30};
int c=30,n =vals.size();
vector<vector<int>> dp(n+1,vector<int> (c+1,0));

for(int i=1;i<=vals.size();i++){
            for(int j=0;j<=c;j++){
                if(j >= wegs[i-1]){
                    dp[i][j] = max(dp[i-1][j] , dp[i-1][j - wegs[i-1]]  + vals[i-1]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
}
 cout << dp[n][c];
}
