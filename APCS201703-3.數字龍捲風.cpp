#include <bits/stdc++.h>
using namespace std;

int main(){
	int n=0;
	cin >> n;
   int d=0;
   cin >> d;
   
	vector<vector<int>> nums(n,vector<int> (n));
	int s=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		   cin>>s;
		   nums[i][j] = s;
	    }
	}
	
	int x=n/2;
	int y=n/2;
	
	int count=1;
	vector<int> dx = {-1,0,1,0};
	vector<int> dy = {0,-1,0,1};
	int step=1;
	
	while(true){
		if(count > n*n) break;
		for(int i=0;i<step;i++){
			cout << nums[x][y];
			x += dx[d];
			y += dy[d];
			count++;
		}
		d = (d+1)%4;
		step++;
	}
}