#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	
	vector<vector<char> > g(n,vector<char> (m));
	bool state[n][m][4] ={};
	bool vis[n][m] = {};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> g[i][j];
		}
	}
	
	int x=0,y=0;
	vis[y][x] = true;
	int dir=0;
	state[y][x][dir] = true;
	int dx[4] ={1,0,-1,0};
	int dy[4] ={0,1,0,-1};
	int u=1;
	while(true)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx>=m||nx<0||ny>=n||ny<0||g[ny][nx] == '#')break;
		x = nx;
		y = ny;
		if(!vis[y][x])
		{
			u++;
			vis[y][x] = true;	
		}
		if(state[y][x][dir] == false)
		
		if(state[y][x][dir]) break;
		state[y][x][dir] =true;
		
		if(g[y][x] == 'L')
		{
			if(dir == 0)dir = 1;
			else if(dir == 1)dir = 0;
			else if(dir == 2)dir = 3;
			else if(dir == 3)dir = 2; 
		}
		else if(g[y][x] == 'R')
		{
			if(dir == 0)dir = 3;
			else if(dir == 3)dir = 0;
			else if(dir == 1)dir = 2;
			else if(dir == 2)dir = 1; 
		}
		
	}
	
	cout << u;
} 
