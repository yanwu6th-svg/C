#include <bits/stdc++.h>
using namespace std;

using arr4 = array<int, 4>;

int main() {
	    int n,m;
	    cin >> n >> m;
	    int g[n][m];
	    vector<vector<vector<int>>> dist(n,vector<vector<int>> (m,vector<int> (4,INT_MAX)));
	    
	    for(int i=0;i<4;i++)
	        dist[0][0][i] = 0;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin >> g[i][j];
	        }
	    }
	    
	    priority_queue<arr4,vector<arr4>,greater<arr4>> pq;
	    for(int i=0;i<4;i++)pq.push({0,0,0,i});
	    
	    vector<int> dx = {0,1,0,-1};
	    vector<int> dy = {1,0,-1,0};
	    
	    while(!pq.empty())
	    {
	        auto [d,x,y,dir] = pq.top();pq.pop();
	        
	        if(d > dist[y][x][dir])continue;
	        
	        for(int i=0;i<4;i++)
	        {
	           int px = x + dx[i];
	           int py = y + dy[i];
	           
	           if(px<0||px>=m||py<0||py>=n||g[py][px]==-1)continue;
	           
	           int df;
	           if(i != dir)df = d + g[py][px]+1;
	           else df = d + g[py][px];
	           if(dist[py][px][i] > df)
	           {
	               dist[py][px][i] = df;
	               
	               pq.push({dist[py][px][i],px,py,i});
	           }
	        }
	    }
	    int ans =*min_element(dist[n-1][m-1].begin(), dist[n-1][m-1].end()); 
	    if(ans == INT_MAX)cout << "-1";
	    else cout << ans;
}
