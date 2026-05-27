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
	vector<int> dx = {0,-1,0,1};
	vector<int> dy = {-1,0,1,0};
	int step=1;
    cout << nums[x][y];
	while(true){
		if(count >= n*n) break;
		for(int j=0;j<2;j++){
            for(int i=0;i<step;i++){
			x += dx[d];
			y += dy[d];

			if(x>=0&&x<n&&y>=0&&y<n){
                cout << nums[x][y];
                count++;
			}

		}
		d = (d+1)%4;
		}


		step++;
	}
}
