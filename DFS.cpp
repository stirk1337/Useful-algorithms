#include <bits/stdc++.h>
/*
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
*/
using namespace std;

#define pb push_back
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define for_i for(int i = 0; i < n; i++)
#define for_j for(int j = 0; j < n; j++)

typedef long long ll;
typedef vector<int> vi;


vi g[5000];
bool used[5000];
void dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

int main()
{
    int n;
    cin >> n;
    for_i
    {
        for_j
        {
            int r;
            cin >> r;
            if (r == 1)
            {
                g[i].pb(j);
            }
        }
    }
    int ans = 0;
    for_i
        used[i] = false;
    for_i
    {
        if (!used[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}