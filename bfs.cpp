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
vi g[100];
bool used[100];
int dist[100];
queue <int> turn;
void bfs(int start) {
	dist[start] = 0;
	used[start] = 1;
	turn.push(start);
	while (!turn.empty())
	{
		int ind = turn.front();
		turn.pop();
		for (int i = 0; i < g[ind].size(); i++)
		{
			if (!used[g[ind][i]])
			{
				turn.push(g[ind][i]);
				used[g[ind][i]] = 1;
				dist[g[ind][i]] = dist[ind] + 1;
			}

		}
	}

}

int main()
{
	int n, s, f, v;
	cin >> n >> s >> f;
	foor(i, n)
		foor(j, n)
		{
			cin >> v;
			if (v == 1)
				g[i].pb(j);
		}
	
	bfs(s-1);
	cout << dist[f-1];


}