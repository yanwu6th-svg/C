#include<bits/stdc++.h>
using namespace std;

using ll = long long
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
	
	vector<vector<int>> dp(k,vector(n,0))
	
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			ll best =0;
			for(int i=l;i<r)
		}
	}
}