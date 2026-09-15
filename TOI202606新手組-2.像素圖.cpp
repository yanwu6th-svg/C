#include <bits/stdc++.h>
using namespace std;

int main() {
	int ly,lx,dy,dx;
	cin >> ly >> lx >> dy >> dx;
	
	int g[ly][lx];
	for(int i=0;i<ly;i++)for(int j=0;j<lx;j++) cin >> g[i][j];
	vector<vector<int>> d1(ly,vector<int>(lx*dx));
	for(int i=0;i<ly;i++)
	{
	    int o=0;
	    for(int j=0;j<lx;j++)
	    {
	        int t = g[i][j];
	        for(int k=0;k<dx;k++)
	        {
	           d1[i][o+k] = t;
	        }
	        o+=dx;
	    }
	}
	vector<vector<int>> d2(ly*dy,vector<int>(lx*dx));
	int o=0;
	for(int i=0;i<ly;i++)
	{
	    for(int j=0;j<dy;j++)
	    {
	        d2[o+j] = d1[i];    
	    }
	    o+= dy;
	}
	
	for(int i=0;i<ly*dy;i++)
	{
	    cout << '\n';
	 for(int j=0;j<lx*dx;j++)
	 {
	     cout <<  d2[i][j] <<" ";   
	 } 
	}
	
}
