#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n=0;
	cin >> n;

	vector<pair<int,int>> nums(n);
	int q=0;
	for(int i=0;i<n;i++){
		cin >> q;
		nums[i].first = q;
	}
	for(int i=0;i<n;i++){
		cin >> q;
		nums[i].second = q;
	}
	
	sort(nums.begin(),nums.end(),[](auto &a,auto & b){
		return a.first * b.second < a.second *b.first;
	});
	long long  aw=0;
	long long  res=0;
	for(int i=1;i<n;i++){
		aw += nums[i-1].first;
		res += aw * nums[i].second;
	}
	cout << res;
}