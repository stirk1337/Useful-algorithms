#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ALL(v) v.begin(), v.end() 
#define sort(v) sort(ALL(v)) 
#define reverse(v) reverse(ALL(v)) 
#define foor(i,n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef vector<int> vi;

//start
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int g[1000][1000];
int color[1000][1000];
int n, m;
int ans;
int dst[1000][1000];
queue <int> xq;
queue <int> yq;
void bfs(int x, int y) {
	xq.push(x);
	yq.push(y);
	color[x][y] = 1;
	while (!xq.empty())
	{
		int indx = xq.front();
		int indy = yq.front();
		xq.pop();
		yq.pop();
		for (int d = 0; d < 4; ++d) {
			int nx = indx + dx[d];
			int ny = indy + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 0 && color[nx][ny] != 1)
			{
				xq.push(nx);
				yq.push(ny);
				color[nx][ny] = 1;
				dst[nx][ny] = dst[indx][indy] + 1;
				//cout << nx+1 << " " << ny+1 << " " << dst[nx][ny] << endl;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	foor(i, n)
		foor(j, m)
			cin >> g[i][j];
	int x1, y1;
	cin >> x1 >> y1;
	x1 -= 1;
	y1 -= 1;
	int x2, y2;
	cin >> x2 >> y2;
	x2 -= 1;
	y2 -= 1;
	if (x1 == x2 && y1 == y2) {
		cout << 0;
		return 0;
	}
	bfs(y1, x1);
	if (dst[y2][x2] == 0)
		cout << -1;
	else
		cout << dst[y2][x2];
}