#include<bits/stdc++.h>
using namespace std;

using ll = long long

ll get_cost(int r,int l,int m,vector<int> &nums,vector<int> &S,vector<int> &SA){
	ll s = S[r] - S[l-1];
	ll sa = SA[r] - SA[l-1];
	
	return llabs(sa-m*s);

}


int main(){
	
	int n=0;
	cin >> n;
	
	int k=0;
	cin >> k;
	
	vector<int> nums(n);
	for(int i=0i<n;i++){
		cin >> nums[i];
	}
	
	vector<int> S(n,0);
	vector<int> SA(n,0);
	for(int i=1;i<n;i++){
		S[i] = S[i-1] + nums[i];
		SA[i] = SA[i-1] + nums[i]*i;
	}
	
	vector<vector<int>> dp(k,vector(n,0));
	
	vector<vector<int>> best_cost(n,vector(n,0));
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			ll best =0;
			for(int i=l;i<r;i++){
				best = max(best,get_cost(r,l,i,nums,S,SA));
			}
			best_cost[r][l] = best;
		}
	}
	
	for(int K=1;K<k;K++){
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				dp[k][i] = max(dp[k-1][i],dp[k-1][j-1]+best_cost[j+1][i])
			}
		}
	}
	
	cout << dp[k][n];
}